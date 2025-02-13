/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:43:44 by ishchyro          #+#    #+#             */
/*   Updated: 2024/12/21 07:08:14 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int		i;
	unsigned char		*char_src;
	unsigned char		*char_dest;

	if (!dest && !src)
		return (NULL);
	i = 0;
	char_src = (unsigned char *)src;
	char_dest = (unsigned char *)dest;
	while (i++ < n)
		char_dest[i - 1] = char_src[i - 1];
	return ((void *)char_dest);
}
