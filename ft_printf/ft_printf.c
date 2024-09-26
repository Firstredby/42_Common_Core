/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:33:48 by ishchyro          #+#    #+#             */
/*   Updated: 2024/09/26 15:31:27 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parser(char c, va_list list)
{
	if (c == 'c')
		return (singchr(va_arg(list, int)));
	else if (c == 's')
		return (string(va_arg(list, char *)));
	else if (c == 'i' || c == 'd')
		return (integer(va_arg(list, int)));
	else if (c == 'p')
		return (vpointer(va_arg(list, unsigned long long)));
	else if (c == 'u')
		return (unsint(va_arg(list, unsigned int)));
	else if (c == 'x')
		return (hexprint(va_arg(list, unsigned int), 'a'));
	else if (c == 'X')
		return (hexprint(va_arg(list, unsigned int), 'A'));
	else if (c == '%')
		return (percent());
	return (0);
}

int	ft_printf(const char *string, ...)
{
	va_list	list;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(list, string);
	while (string[i])
	{
		if (string[i] == '%')
		{
			len += parser(string[i + 1], list);
			i++;
		}
		else
			len += write(1, &string[i], 1);
		i++;
	}
	va_end(list);
	return (len);
}
