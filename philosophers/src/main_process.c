/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:32:25 by ishchyro          #+#    #+#             */
/*   Updated: 2025/05/16 17:32:03 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_action(t_philo *philo, int action)
{
	size_t		action_time;
	static int	flag = 1;

	pthread_mutex_lock(&philo->data->print);
	action_time = curr_time() - philo->data->begin;
	if (action == 1 && flag)
		printf("%zu %i has taken a fork\n", action_time, philo->index + 1);
	else if (action == 2 && flag)
		printf("%zu %i is eating\n", action_time, philo->index + 1);
	else if (action == 3 && flag)
		printf("%zu %i is sleeping\n", action_time, philo->index + 1);
	else if (action == 4 && flag)
		printf("%zu %i is thinking\n", action_time, philo->index + 1);
	else if (action == 5 && flag)
		(printf("%zu %i died\n", action_time, philo->index + 1), flag = 0);
	pthread_mutex_unlock(&philo->data->print);
}

void	take_fork(t_philo *philo)
{
	int	np;

	np = (philo->index + 1) % philo->data->nop;
	if (!(philo->index % 2))
	{
		pthread_mutex_lock(&philo->data->philo[np].fork);
		philo_action(philo, 1);
		if (is_dead(philo))
			return ((void)pthread_mutex_unlock(&philo->data->philo[np].fork));
		pthread_mutex_lock(&philo->fork);
	}
	else
	{
		pthread_mutex_lock(&philo->fork);
		philo_action(philo, 1);
		if (is_dead(philo))
			return ((void)pthread_mutex_unlock(&philo->fork));
		pthread_mutex_lock(&philo->data->philo[np].fork);
	}
}

void	philo_eat(t_philo *philo)
{
	int	np;

	np = (philo->index + 1) % philo->data->nop;
	take_fork(philo);
	if (is_dead(philo))
		return ;
	pthread_mutex_lock(&philo->data->status);
	philo->lte = curr_time();
	pthread_mutex_unlock(&philo->data->status);
	philo_action(philo, 2);
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
		if ((philo->data->nop % 2) && philo->data->tte > philo->data->tts
			&& philo->data->nop - 1 == philo->index)
			(philo_action(philo, 4),
				ft_usleep(philo, philo->data->tte + philo->data->tts));
		else if ((philo->data->nop % 2) && philo->data->tte > philo->data->tts)
			(philo_action(philo, 4),
				ft_usleep(philo, philo->data->tte - philo->data->tts));
		else if ((philo->data->nop % 2) && philo->data->tte < philo->data->tts)
			(philo_action(philo, 4),
				ft_usleep(philo, philo->data->ttd
					- philo->data->tts - philo->data->tte - 1));
		else
			(philo_action(philo, 4), ft_usleep(philo, philo->data->tte));
	}
	else if (philo->eaten == 0 && philo->data->nop > 1)
	{
		if ((philo->index % 2))
			(philo_action(philo, 4), ft_usleep(philo, philo->data->tte));
		else if ((philo->data->nop % 2) && philo->data->nop - 1 == philo->index)
			(philo_action(philo, 4), ft_usleep(philo, philo->data->tte * 2));
	}
}

void	*philoop(void *d)
{
	t_philo	*philo;

	philo = (t_philo *)d;
	if (all_ready(philo))
		return (NULL);
	if ((philo->index % 2))
		usleep(200);
	while (!is_dead(philo))
	{
		philo_think(philo, 0);
		if (philo->eaten != philo->data->nte)
			philo_eat(philo);
		else
			ft_usleep(philo, philo->data->tte * 10);
		(philo_action(philo, 3), ft_usleep(philo, philo->data->tts));
		pthread_mutex_lock(&philo->data->status);
		if (all_philos_eat(philo->data))
		{
			pthread_mutex_unlock(&philo->data->status);
			break ;
		}
		pthread_mutex_unlock(&philo->data->status);
		philo_think(philo, 1);
	}
	return (NULL);
}
