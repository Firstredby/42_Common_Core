/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:12:23 by ishchyro          #+#    #+#             */
/*   Updated: 2024/09/17 14:09:41 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*min_put(void)
{
	char	*str;

	str = ft_calloc(12, sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	return (str);
}

static char	*max_put(void)
{
	char	*str;

	str = ft_calloc(11, sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '2';
	str[1] = '1';
	str[2] = '4';
	str[3] = '7';
	str[4] = '4';
	str[5] = '8';
	str[6] = '3';
	str[7] = '6';
	str[8] = '4';
	str[9] = '7';
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
	if (n == -2147483648)
		return (min_put());
	if (n == 2147483647)
		return (max_put());
	numstr = filler(copy_n);
	if (n < 0 && numstr)
		numstr[0] = '-';
	return (numstr);
}
