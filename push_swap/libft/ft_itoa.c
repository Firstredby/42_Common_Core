/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:12:23 by ishchyro          #+#    #+#             */
/*   Updated: 2024/12/11 18:08:16 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*edge_values(int n)
{
	char	*str;

	if (n == -2147483648)
	{
		str = ft_calloc(12, sizeof(char));
		if (!str)
			return (NULL);
		str = "-2147483648\0";
	}
	else
	{
		str = ft_calloc(11, sizeof(char));
		if (!str)
			return (NULL);
		str = "2147483647\0";
	}
	return (str);
}

static char	*filler(int copy_n)
{
	char	*str;
	int		i;
	int		size;

	size = 0;
	if (copy_n < 0)
	{
		size++;
		copy_n = -copy_n;
	}
	i = copy_n;
	while (copy_n)
	{
		size++;
		copy_n /= 10;
	}
	str = ft_calloc(size + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (size)
	{
		str[--size] = i % 10 + '0';
		i /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*numstr;
	int		copy_n;

	copy_n = n;
	if (n == 0)
	{
		numstr = ft_calloc(2, sizeof(char));
		if (!numstr)
			return (NULL);
		numstr[0] = '0';
		return (numstr);
	}
	if (n == -2147483648 || n == 2147483647)
		return (edge_values(n));
	numstr = filler(copy_n);
	if (n < 0 && numstr)
		numstr[0] = '-';
	return (numstr);
}
