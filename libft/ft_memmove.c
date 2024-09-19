/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:24:43 by ishchyro          #+#    #+#             */
/*   Updated: 2024/09/18 19:20:03 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy(unsigned char *char_src,
		unsigned char *char_dest, size_t n)
{
	while (--n)
		char_dest[n] = char_src[n];
	char_dest[n] = char_src[n];
}

void	*ft_memmove(void *dest, const	void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*char_src;
	unsigned char	*char_dest;

	if (!dest && !src)
		return (NULL);
	if (!n)
		return (dest);
	i = 0;
	char_src = (unsigned char *) src;
	char_dest = (unsigned char *) dest;
	if (char_dest > char_src)
	{
		copy(char_src, char_dest, n);
	}
	else
	{
		while ((size_t)i < n)
		{
			char_dest[i] = char_src[i];
			i++;
		}
	}
	return ((void *)char_dest);
}
