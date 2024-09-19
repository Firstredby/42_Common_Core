/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:43:44 by ishchyro          #+#    #+#             */
/*   Updated: 2024/09/12 16:51:48 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int		i;
	unsigned char		*char_src;
	unsigned char		*char_dest;

	i = 0;
	if (!dest && !src)
		return (NULL);
	char_src = (unsigned char *)src;
	char_dest = (unsigned char *)dest;
	while (i < n)
	{
		char_dest[i] = char_src[i];
		i++;
	}
	return ((void *)char_dest);
}
