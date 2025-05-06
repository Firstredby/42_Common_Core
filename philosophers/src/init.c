/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 02:56:43 by ishchyro          #+#    #+#             */
/*   Updated: 2025/05/04 21:21:44 by ishchyro         ###   ########.fr       */
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
			return (philo_free(philo, rounds), error_cases(MALLOC));
		rounds++;
	}
	return (0);
}

int	data_init(t_data *data)
{
	data->begin = curr_time();
	data->dead = 0;
	pthread_mutex_init(&data->action, NULL);
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->status, NULL);
	pthread_mutex_init(&data->meal_check, NULL);
	return (0);
}
