/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 04:23:23 by ishchyro          #+#    #+#             */
/*   Updated: 2025/01/13 16:33:27 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig)
{
	static int				i = 0;
	static unsigned char	bit = 0;

	if (sig == SIGUSR1)
		bit = (bit << 1) | 1;
	else
		bit = bit << 1;
	i++;
	if (i == 8)
	{
		ft_printf("%c", bit);
		i = 0;
		bit = 0;
	}
}

int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
	}
	return (0);
}
