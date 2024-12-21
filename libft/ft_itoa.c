/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:12:23 by ishchyro          #+#    #+#             */
/*   Updated: 2024/12/21 07:07:36 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*three_apostles(int n)
{
	char	*str;

	if (n == 0)
		return (str = ft_strdup("0"));
	else if (n == -2147483648)
		return (str = ft_strdup("-2147483648"));
	else
		return (str = ft_strdup("2147483647"));
}

char	*ft_itoa(int n)
{
	char	*numstr;
	int		copy_n;
	int		size;
	int		sign;

	sign = n;
	copy_n = n;
	if (n == -2147483648 || n == 2147483647 || n == 0)
		return (three_apostles(n));
	size = 0;
	if (copy_n < 0 && ++size)
		n = -n;
	while (copy_n != 0 && ++size)
		copy_n /= 10;
	numstr = ft_calloc(size + 1, sizeof(char));
	while (size && numstr)
	{
		numstr[--size] = n % 10 + '0';
		n /= 10;
	}
	if (sign < 0 && numstr)
		numstr[0] = '-';
	return (numstr);
}
