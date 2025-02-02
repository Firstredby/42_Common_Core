/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 04:23:23 by ishchyro          #+#    #+#             */
/*   Updated: 2025/02/02 15:04:36 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig, siginfo_t *info, void *content)
{
	static int				i = 0;
	static unsigned char	bit = 0;
	static unsigned char	byte = 0;
	static unsigned char	msg[131072];

	(void) content;
	if (sig == SIGUSR1)
		byte = (byte << 1) | 1;
	else
		byte = byte << 1;
	bit++;
	if (bit == 8)
	{
		msg[i++] = byte;
		if (!byte)
		{
			i = 0;
			ft_printf("%s\n", msg);
			kill(info->si_pid, SIGUSR1);
		}
		bit = 0;
		byte = 0;
	}
	kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("Server PID: %d\n", getpid());
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf("Did not recieved Signal 1!");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("Did not recieved Signal 0!");
	while (1)
		pause();
	return (0);
}
