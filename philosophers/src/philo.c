/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:23:15 by ishchyro          #+#    #+#             */
/*   Updated: 2025/05/11 03:57:55 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_dead(t_philo *philo)
{
	size_t	time;

	pthread_mutex_lock(&philo->data->status);
	time = curr_time() - philo->lte;
	if (philo->data->dead)
		return (pthread_mutex_unlock(&philo->data->status), true);
	else if (philo->lte && time > philo->data->ttd)
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

void	philo_start(t_data *data)
{
	int	i;

	i = 0;
	data_init(data);
	if (philo_init(data))
		return ;
	philo_create(data);
	while (1)
	{
		usleep(500);
		pthread_mutex_lock(&data->status);
		if (data->dead)
			break ;
		else if (all_philos_eat(data))
			data->dead = 1;
		pthread_mutex_unlock(&data->status);
	}
	pthread_mutex_unlock(&data->status);
	while (i < data->nop)
		pthread_join(data->philo[i++].thread, NULL);
}

void	solo(void) //need to rework
{
	printf("0 1 has taken a fork\n0 1 died\n");
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 5 || ac > 6)
		return (error_cases(WRONG_INPUT));
	if (!is_negative(av))
		return (error_cases(NN));
	if (!arg_check(av, ac))
		return (error_cases(NAN));
	data.nop = ft_atoi(av[1]);
	if (data.nop == 1)
		return (solo(), 0);
	data.ttd = ft_atoi(av[2]);
	data.tte = ft_atoi(av[3]);
	data.tts = ft_atoi(av[4]);
	if (av[5])
		data.nte = ft_atoi(av[5]);
	else
		data.nte = -1;
	if (data.nop == 0 || data.ttd == 0 || data.tte == 0
		|| data.tts == 0 || data.nte == 0)
		return (error_cases(ZERO));
	philo_start(&data);
	philo_free(data.philo, data.nop);
	return (0);
}
