/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:24:43 by ishchyro          #+#    #+#             */
/*   Updated: 2024/12/21 05:48:53 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		while ((int)--n >= 0)
			char_dest[n] = char_src[n];
	else
		while (i++ < n)
			char_dest[i - 1] = char_src[i - 1];
	return ((void *)char_dest);
}
