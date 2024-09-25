/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:33:48 by ishchyro          #+#    #+#             */
/*   Updated: 2024/09/25 18:28:02 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parser(char c, const char *str)
{
	if (c == 'c')
		return (singchr(str));
	else if (c == 's')
		return (string(str));
	else if (c == 'i' || c == 'd')
		return (integer(str));
	else if (c == 'p')
		return (vpointer(str));
	else if (c == 'u')
		return (unsint(str));
	else if (c == 'x')
		return (hexalow(str));
	else if (c == 'X')
		return (hexaupp(str));
	else if (c == '%')
		return (percent());
	return (0);
}

int ft_printf(const char *string, ...)
{
	va_list list;
	int	i;
	int	len;

	i = 0;
	len = 0;
	va_start(list, string);
	while(string[i])
	{
		if (string[i] == '%')
			len += parser(string[i + 1], string);
		else
			len += write(1, &string[i], 1);
	}
	return (len);
}