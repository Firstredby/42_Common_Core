/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:44:03 by ishchyro          #+#    #+#             */
/*   Updated: 2025/05/11 03:56:33 by ishchyro         ###   ########.fr       */
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

int	ft_atoi(char *str)
{
	int		num;
	bool	is_negative;

	num = 0;
	is_negative = false;
	while (*str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			is_negative = true;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + *str - '0';
		str++;
	}
	if (is_negative)
		return (num * -1);
	return (num);
}

bool	is_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' && *(str + 1))
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

bool	is_negative(char **params)
{
	int	i;

	i = 0;
	while (params[i])
		if (params[i++][0] == '-')
			return (false);	
	return (true);
}

bool	arg_check(char **params, int rounds)
{
	int	i;

	i = 1;
	while (i <= rounds - 1)
		if (!is_num(params[i++]))
			return (false);
	return (true);
}

void	philo_free(t_philo *philo, size_t philos)
{
	unsigned int	i;

	i = 0;
	if (!philo)
		return ;
	while (i < philos)
		pthread_mutex_destroy(&philo[i++].fork);
	free(philo);
}
