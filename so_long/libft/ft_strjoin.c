/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:28:15 by ishchyro          #+#    #+#             */
/*   Updated: 2024/12/21 07:25:48 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstring;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (newstring = ft_calloc(1, 1));
	newstring = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	i = 0;
	j = 0;
	while (s1[j] && newstring)
		newstring[i++] = s1[j++];
	j = 0;
	while (s2[j] && newstring)
		newstring[i++] = s2[j++];
	return (newstring);
}
