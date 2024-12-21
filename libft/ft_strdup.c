/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:57:24 by ishchyro          #+#    #+#             */
/*   Updated: 2024/12/21 07:23:45 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dup;
	int		i;

	dup = ft_calloc(sizeof(char), ft_strlen(src) + 1);
	i = 0;
	while (src[i++] && dup)
		dup[i - 1] = src[i - 1];
	return (dup);
}
