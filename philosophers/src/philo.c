/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:23:15 by ishchyro          #+#    #+#             */
/*   Updated: 2025/07/23 18:49:01 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_dead(t_philo *philo)
{
	size_t	time;

	pthread_mutex_lock(&philo->data->status);
	if (philo->data->dead)
		return (pthread_mutex_unlock(&philo->data->status), true);
	time = curr_time() - philo->lte;
	if (philo->lte && time > philo->data->ttd)
	{
		philo->data->dead = 1;
		return (pthread_mutex_unlock(&philo->data->status),
			philo_action(philo, 5), true);
	}
	return (pthread_mutex_unlock(&philo->data->status), false);
}

bool	all_philos_eat(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nop)
	{
		pthread_mutex_lock(&data->meal_check);
		if (data->philo[i].eaten != data->nte)
			return (pthread_mutex_unlock(&data->meal_check), false);
		pthread_mutex_unlock(&data->meal_check);
	}
	return (i);
}

int	all_ready(t_philo *philo)
{
	if (philo->data->nop == 1)
		return (1);
	while (1)
	{
		pthread_mutex_lock(&philo->data->inout);
		if (philo->data->all_ready == 1)
		{
			pthread_mutex_unlock(&philo->data->inout);
			break ;
		}
		if (philo->data->all_ready == -1)
			return (pthread_mutex_unlock(&philo->data->inout), 1);
		pthread_mutex_unlock(&philo->data->inout);
		usleep(500);
	}
	return (0);
}

void	philo_start(t_data *data)
{
	int	i;

	i = 0;
	if (data_init(data) || philo_init(data) || philo_create(data))
		return ;
	if (data->nop == 1)
	{
		philo_action(&data->philo[0], 1);
		usleep(data->ttd * 1000 + 100);
		philo_action(&data->philo[0], 5);
		return (philo_free(data->philo, data->nop), mutex_free(data));
	}
	while (1)
	{
		pthread_mutex_lock(&data->status);
		if (data->dead)
			break ;
		else if (all_philos_eat(data))
			data->dead = 1;
		pthread_mutex_unlock(&data->status);
		usleep(1000);
	}
	pthread_mutex_unlock(&data->status);
	philo_free(data->philo, data->nop);
	mutex_free(data);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 5 || ac > 6)
		return (error_cases(WRONG_INPUT));
	if (!value_validation(av))
		return (error_cases(NAN));
	data.nop = ft_philo_atol(av[1]);
	data.ttd = ft_philo_atol(av[2]);
	data.tte = ft_philo_atol(av[3]);
	data.tts = ft_philo_atol(av[4]);
	if (av[5])
		data.nte = ft_philo_atol(av[5]);
	else
		data.nte = -1;
	if (data.nop == 0 || data.ttd == 0 || data.tte == 0
		|| data.tts == 0 || data.nte == 0)
		return (error_cases(ZERO));
	philo_start(&data);
	return (0);
}
