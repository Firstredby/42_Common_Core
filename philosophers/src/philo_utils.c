/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:44:03 by ishchyro          #+#    #+#             */
/*   Updated: 2025/07/09 14:47:56 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	curr_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		error_cases(TIME);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long	ft_philo_atol(char *str)
{
	long	num;

	num = 0;
	while (*str == ' ')
		str++;
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + *str - '0';
		str++;
	}
	return (num);
}

bool	is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '+' && *(str + 1))
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	if (i > 10)
		return (false);
	return (true);
}

bool	value_validation(char **params)
{
	int		i;
	long	value;

	i = 1;
	while (params[i])
	{
		if (!is_num(params[i]))
			return (false);
		value = ft_philo_atol(params[i++]);
		if (value < 0 || value > 2147483647)
			return (false);
	}
	return (true);
}

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