/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 04:23:21 by ishchyro          #+#    #+#             */
/*   Updated: 2025/01/23 16:07:10 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	msg(int pid, char *str)
{
	int				i;
	unsigned int	bit;

	i = 0;
	while (*str)
	{
		bit = *str;
		while (i < 8)
		{
			if (bit << i & 128)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i++;
			usleep(100);
		}
		str++;
		i = 0;
	}
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		ft_printf("Wrong input!\n");
		ft_printf("Please note that first paramether should ");
		ft_printf("be server id, then a message!");
		exit(-1);
	}
	if (av[1][0] == '0' || av[1][0] == '-' || av[1][0] == '+'
		|| ft_atoi(av[1]) > 419304)
	{
		ft_printf("Invalid PID!");
		exit(-1);
	}
	msg(ft_atoi(av[1]), av[2]);
	return (0);
}
