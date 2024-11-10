/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functionsone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:38:41 by ishchyro          #+#    #+#             */
/*   Updated: 2024/11/10 14:47:56 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	singchr(char c)
{
	return (write(1, &c, 1));
}

int	string(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	integer(int num)
{
	int	len;

	len = 0;
	if (num == -2147483648)
		return (write(1, "-2147483648", 11));
	else if (!num)
		return (write(1, "0", 1));
	else
	{
		if (num < 0)
		{
			len += write(1, "-", 1);
			num = -num;
		}
		if (num > 9)
		{
			len += integer(num / 10);
			ft_putchar_fd(num % 10 + '0', 1);
		}
		else
			ft_putchar_fd(num + '0', 1);
	}
	len++;
	return (len);
}

int	vpointer(unsigned long long addr)
{
	if (addr == 0)
		return (write(1, "(nil)", 5));
	else
		return (write(1, "0x", 2) + hexprint(addr, 'a'));
}

int	unsint(unsigned int num)
{
	static int	len;

	len = 0;
	if (num > 9)
	{
		unsint(num / 10);
		len++;
	}
	else
		len++;
	ft_putchar_fd(num % 10 + '0', 1);
	return (len);
}
