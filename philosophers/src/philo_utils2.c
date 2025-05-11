/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:55:37 by ishchyro          #+#    #+#             */
/*   Updated: 2025/05/11 03:28:58 by ishchyro         ###   ########.fr       */
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
		return (printf("Ah, yes, just toss in some random characters and hope for the"
				" best. Spoiler alert: it didn’t work. Try something that "
				"actually makes sense\n"), 74);
	else if (case_id == MALLOC)
		return (printf("Your RAM is ass. Aborted\n"), 12);
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
	int		i;

	i = 0;
	start = curr_time();
	end = time;
	while ((curr_time() - start) < end)
	{
		while (i < philo->data->nop)
		{
			if (is_dead(&philo->data->philo[i++]))
				end = 0;
		}
		usleep(end / 1000);
		i = 0;
	}
}
