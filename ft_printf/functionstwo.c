/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functionstwo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:56:36 by ishchyro          #+#    #+#             */
/*   Updated: 2024/09/25 22:02:53 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexalow(void *str)
{
	size_t	ptr;
	
	ptr = (size_t)str;
	return (hexfound(ptr, 'a'));	
}

int	hexaupp(void *str)
{
	size_t	ptr;
	
	ptr = (size_t)str;
	return (hexfound(ptr, 'A'));
}

int	hexfound(size_t ptr, char chr)
{
	static int	len;

	len = 0;
	if (ptr > 15)
		return (ptr / 16);
	else
	{
		if (ptr <= 9)
			ft_putchar_fd(ptr % 16 + '0', 1);
		else
			ft_putchar_fd(ptr % 16 + chr - 10, 1);
		len++;
	}
	return (len);
}

int	percent(void)
{
	return(write(1, "%", 1));
}