/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functionsone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:38:41 by ishchyro          #+#    #+#             */
/*   Updated: 2024/09/25 18:17:13 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	singchr(char c)
{
	return (write(1, &c, 1));
}

int string(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int integer(int num)
{
	static int	len;

	len = 0;
	if (num == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (num < 0)
		{
			write(1, "-", 1);
			num *= -1;
		}
		if (num > 9)
		{
			integer(num / 10);
			len++;
		}
		else
			len++;
	}
	ft_putchar_fd(num % 10 + '0', 1);
	return (len);
}

int vpointer(void *str)
{
	return (write(1, "0x", 2) + hexalow(str));
}

int unsint(unsigned int num)
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