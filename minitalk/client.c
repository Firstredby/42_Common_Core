/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 04:23:21 by ishchyro          #+#    #+#             */
/*   Updated: 2025/02/02 15:15:53 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_await;

void	respond(int i)
{
	if (i == SIGUSR1)
		ft_printf("Signal sended successfuly!");
	g_await = 0;
}

void	send_eol(int pid)
{
	int	i;

	i = 8;
	while (i--)
	{
		g_await = 1;
		kill(pid, SIGUSR2);
		while (g_await)
			pause();
	}
}

void	msg(int pid, char *str)
{
	int				i;
	unsigned int	bit;

	while (*str)
	{
		i = 0;
		bit = *str;
		while (i < 8)
		{
			g_await = 1;
			if (bit << i & 128)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i++;
			while (g_await)
				pause();
		}
		str++;
	}
	send_eol(pid);
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
	if (ft_atoi(av[1]) <= 0 || av[1][0] == '+'
		|| ft_atoi(av[1]) > 419304)
		ft_printf("Invalid PID!");
	signal(SIGUSR1, &respond);
	signal(SIGUSR2, &respond);
	msg(ft_atoi(av[1]), av[2]);
	return (0);
}
