/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:35:39 by ishchyro          #+#    #+#             */
/*   Updated: 2024/12/21 06:23:13 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const	void *s1, const	void *s2, size_t n)
{
	unsigned char	*char_str1;
	unsigned char	*char_str2;

	char_str1 = (unsigned char *)s1;
	char_str2 = (unsigned char *)s2;
	if (!n)
		return (0);
	while (*char_str1 == *char_str2 && --n)
	{
		char_str1++;
		char_str2++;
	}
	return (*char_str1 - *char_str2);
}
