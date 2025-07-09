/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:32:25 by ishchyro          #+#    #+#             */
/*   Updated: 2025/07/09 15:09:57 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_fork(t_philo *philo)
{
	int	np;

	np = (philo->index + 1) % philo->data->nop;
	if (!(philo->index % 2))
	{
		pthread_mutex_lock(&philo->data->philo[np].fork);
		philo_action(philo, 1);
		if (is_dead(philo) || philo->data->dead)
			return (pthread_mutex_unlock(&philo->data->philo[np].fork), 1);
		pthread_mutex_lock(&philo->fork);
	}
	else
	{
		pthread_mutex_lock(&philo->fork);
		philo_action(philo, 1);
		if (is_dead(philo) || philo->data->dead)
			return (pthread_mutex_unlock(&philo->fork), 1);
		pthread_mutex_lock(&philo->data->philo[np].fork);
	}
	return (0);
}

void	philo_eat(t_philo *philo)
{
	int	np;

	np = (philo->index + 1) % philo->data->nop;
	if (take_fork(philo))
		return ;
	philo_action(philo, 2);
	pthread_mutex_lock(&philo->data->status);
	philo->lte = curr_time();
	pthread_mutex_unlock(&philo->data->status);
	ft_usleep(philo, philo->data->tte);
	pthread_mutex_lock(&philo->data->status);
	philo->eaten++;
	pthread_mutex_unlock(&philo->data->status);
	pthread_mutex_unlock(&philo->data->philo[np].fork);
	pthread_mutex_unlock(&philo->fork);
}

void	philo_think(t_philo *philo, int routine)
{
	if (routine == 1)
	{
		if (!(philo->data->nop % 2))
		{
			if (philo->data->ttd - philo->data->tte
				- philo->data->tts >= 10)
				(philo_action(philo, 4),
					ft_usleep(philo, philo->data->ttd - philo->data->tte
						- philo->data->tts - 10));
			else
				return ;
		}
		else if ((philo->data->nop % 2) && philo->data->tte > philo->data->tts)
			(philo_action(philo, 4), ft_usleep(philo, philo->data->tte));
		else if ((philo->data->nop % 2) && philo->data->tte <= philo->data->tts)
			(philo_action(philo, 4), ft_usleep(philo, philo->data->tts));
	}
	else if (philo->eaten == 0 && philo->data->nop > 1)
	{
		if ((philo->index % 2))
			(philo_action(philo, 4), ft_usleep(philo, philo->data->tte));
		else if ((philo->data->nop % 2) && philo->data->nop - 1 == philo->index)
			(philo_action(philo, 4), ft_usleep(philo, philo->data->tte * 2));
	}
}

void	philoop(t_philo *philo)
{
	while (!is_dead(philo))
	{
		philo_think(philo, 0);
		if (philo->eaten != philo->data->nte)
			philo_eat(philo);
		else
			ft_usleep(philo, philo->data->tte * 10);
		(philo_action(philo, 3), ft_usleep(philo, philo->data->tts));
		pthread_mutex_lock(&philo->data->status);
		if (all_philos_eat(philo->data) || philo->data->dead)
		{
			pthread_mutex_unlock(&philo->data->status);
			break ;
		}
		pthread_mutex_unlock(&philo->data->status);
		philo_think(philo, 1);
	}
}

void	*routine(void *d)
{
	t_philo	*philo;

	philo = (t_philo *)d;
	if (all_ready(philo))
		return (philo->data->finish++, NULL);
	else
	{
		if ((philo->index % 2))
			usleep(200);
		philoop(philo);
		pthread_mutex_lock(&philo->data->status);
		philo->data->finish++;
		pthread_mutex_unlock(&philo->data->status);
	}
	return (NULL);
}
