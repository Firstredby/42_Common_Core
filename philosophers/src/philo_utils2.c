/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:55:37 by ishchyro          #+#    #+#             */
/*   Updated: 2025/07/09 14:39:23 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_cases(int case_id)
{
	if (case_id == WRONG_INPUT)
		return (printf("Do you even know how to use it?\nLet me help you:\n"
				"./philo number_of_philos time_to_die time_to_eat time_to_sleep"
				" [num_of_times_each_philos_must_eat]\n"
				"This one should work, trust me\n"), 22);
	else if (case_id == NAN)
		return (printf("Ah, yes, just toss in some random characters and hope "
				"for the best. Spoiler alert: it didn’t work. Try something "
				"that actually makes sense\n"), 74);
	else if (case_id == MALLOC)
		return (printf("Oops! Seems like your potato can not handle such a "
				"simple case like this one\n"), 12);
	else if (case_id == TIME)
		return (printf("WTF!? What time do you live in actually?\n"), 5);
	else if (case_id == NN)
		return (printf("Do you think this is funny?\n"), 22);
	else if (case_id == ZERO)
		return (printf("Divide yourself by 0\n"), 22);
	return (0);
}

void	ft_usleep(t_philo *philo, size_t time)
{
	size_t	start;
	size_t	end;

	start = curr_time();
	end = time;
	while ((curr_time() - start) < end)
	{
		if (is_dead(philo))
			break ;
		usleep(end / 1000);
	}
}

void	philo_free(t_philo *philo, size_t philos)
{
	unsigned int	i;

	i = 0;
	if (!philo)
		return ;
	while ((int)philo->data->finish < philo->data->nop)
		usleep(500);
	while (i < philos)
		pthread_join(philo[i++].thread, NULL);
	i = 0;
	while (i < philos)
		pthread_mutex_destroy(&philo[i++].fork);
	free(philo);
}

void	fail_free(t_philo *philo, size_t philos, size_t mutexes)
{
	unsigned int	i;

	i = 0;
	if (!philo)
		return ;
	while (i < philos || i < mutexes)
	{
		if (i < philos && philo[i].thread)
			pthread_join(philo[i].thread, NULL);
		if (i < mutexes)
			pthread_mutex_destroy(&philo[i].fork);
		i++;
	}
	free(philo);
}

void	mutex_free(t_data *data)
{
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->status);
	pthread_mutex_destroy(&data->meal_check);
}
