/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:32:25 by ishchyro          #+#    #+#             */
/*   Updated: 2025/05/06 19:47:06 by ishchyro         ###   ########.fr       */
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

bool	is_dead(t_philo *philo)
{
	bool	res;
	size_t	time;

	pthread_mutex_lock(&philo->data->status);
	res = false;
	time = curr_time() - philo->lte;
	if (philo->data->dead)
		res = true;
	else if (philo->lte && time > philo->data->ttd)
	{
		philo->data->dead = 1;
		res = true;
		philo_action(philo, 5);
	}
	pthread_mutex_unlock(&philo->data->status);
	return (res);
}

void	take_fork(t_philo *philo, pthread_mutex_t *l_fork, 
	pthread_mutex_t *r_fork)
{
	pthread_mutex_lock(r_fork);
	philo_action(philo, 1);
	if (is_dead(philo))
		return ((void )pthread_mutex_unlock(r_fork));
	pthread_mutex_lock(l_fork);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;

	l_fork = &philo->fork;
	r_fork = &philo->data->philo[(philo->index + 1) % philo->data->nop].fork;
	if (!(philo->index % 2))
		take_fork(philo, l_fork, r_fork);
	else
		take_fork(philo, r_fork, l_fork);
	philo_action(philo, 2);
	ft_usleep(philo, philo->data->tte);
	pthread_mutex_lock(&philo->data->meal_check);
	philo->lte = curr_time();
	philo->eaten++;
	pthread_mutex_unlock(&philo->data->meal_check);
	pthread_mutex_unlock(r_fork);
	pthread_mutex_unlock(l_fork);
}

void	*philoop(void *d)
{
	t_philo	*philo;

	philo = (t_philo *)d;
	if (philo->index % 2)
		usleep(100);
	while (!is_dead(philo))
	{
		if (philo->lte <= philo->data->ttd && (philo->index % 2 || philo->index == philo->data->nop - 1))
			philo_action(philo, 4);
		if (philo->eaten != philo->data->nte)
			philo_eat(philo);
		philo_action(philo, 3);
		ft_usleep(philo, philo->data->tts);
		if (is_dead(philo))
			break ;
		philo_action(philo, 4);
		ft_usleep(philo, (philo->data->tte + philo->data->tts) / 2);
	}
	return (NULL);
}
