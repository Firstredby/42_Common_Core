/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functionstwo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:56:36 by ishchyro          #+#    #+#             */
/*   Updated: 2025/01/13 16:37:12 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

int	hexprint(unsigned long long addr, char c)
{
	int	len;

	len = 0;
	if (addr == 0)
		len++;
	hexfound(addr, c);
	while (addr)
	{
		len++;
		addr /= 16;
	}
	return (len);
}

void	hexfound(unsigned long long addr, char chr)
{
	if (addr > 15)
	{
		hexfound(addr / 16, chr);
		hexfound(addr % 16, chr);
	}
	else
	{
		if (addr <= 9)
			ft_putchar_fd(addr % 16 + '0', 1);
		else
			ft_putchar_fd(addr % 16 + chr - 10, 1);
	}
}

int	percent(void)
{
	return (write(1, "%", 1));
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
