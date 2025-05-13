/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 02:56:43 by ishchyro          #+#    #+#             */
/*   Updated: 2025/05/13 19:18:05 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_init(t_data *data)
{
	int		rounds;
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo) * data->nop);
	if (!philo)
		return (error_cases(MALLOC));
	rounds = 0;
	data->philo = philo;
	while (rounds < data->nop)
	{
		philo[rounds].index = rounds;
		philo[rounds].data = 0;
		philo[rounds].lte = 0;
		philo[rounds].data = data;
		philo[rounds].eaten = 0;
		if (pthread_mutex_init(&philo[rounds].fork, NULL))
			return (philo_free(data->philo, rounds),
				mutex_free(data),
				error_cases(MALLOC));
		rounds++;
	}
	return (0);
}

int	data_init(t_data *data)
{
	data->begin = curr_time();
	data->dead = 0;
	data->all_ready = 0;
	if (pthread_mutex_init(&data->action, NULL))
		return (1);
	if (pthread_mutex_init(&data->print, NULL))
		return (pthread_mutex_destroy(&data->action), 1);
	if (pthread_mutex_init(&data->status, NULL))
		return (pthread_mutex_destroy(&data->action),
			pthread_mutex_destroy(&data->print), 1);
	if (pthread_mutex_init(&data->meal_check, NULL))
		return (pthread_mutex_destroy(&data->action),
			pthread_mutex_destroy(&data->print),
			pthread_mutex_destroy(&data->status), 1);
	return (0);
}

int	philo_create(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nop)
	{
		if (pthread_create(&data->philo[i].thread, NULL,
				&philoop, &data->philo[i]))
		{
			pthread_mutex_lock(&data->status);
			data->all_ready = -1;
			pthread_mutex_unlock(&data->status);
			usleep(1000);
			while (--i >= 0)
				pthread_join(data->philo[i].thread, NULL);
			philo_free(data->philo, data->nop);
			mutex_free(data);
			return (error_cases(MALLOC));
		}
		i++;
	}
	pthread_mutex_lock(&data->status);
	data->all_ready = 1;
	pthread_mutex_unlock(&data->status);
	return (0);
}
