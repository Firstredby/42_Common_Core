/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:35:39 by ishchyro          #+#    #+#             */
/*   Updated: 2024/09/10 16:13:06 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const	void *s1, const	void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*char_str1;
	unsigned char	*char_str2;

	i = 0;
	char_str1 = (unsigned char *)s1;
	char_str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (*char_str1 == *char_str2 && i < n - 1)
	{
		i++;
		char_str1++;
		char_str2++;
	}
	if (i == n)
		i--;
	return (*char_str1 - *char_str2);
}
