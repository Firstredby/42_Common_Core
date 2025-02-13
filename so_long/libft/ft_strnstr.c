/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:59:12 by ishchyro          #+#    #+#             */
/*   Updated: 2024/12/21 06:25:40 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*b;
	char			*l;

	i = 0;
	j = 0;
	b = (char *)big;
	l = (char *)little;
	if (!*l)
		return (b);
	while (b[i] && i < len)
	{
		while (j + i < len && b[i + j] == l[j] && b[i + j] != '\0')
			j++;
		if (l[j] == '\0')
			return (&b[i]);
		i++;
		j = 0;
	}
	return (0);
}
