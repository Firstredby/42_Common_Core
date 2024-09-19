/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:28:15 by ishchyro          #+#    #+#             */
/*   Updated: 2024/09/10 17:14:58 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstring;
	int		i;
	int		j;

	if (!s1 && !s2)
	{
		newstring = malloc(1);
		*newstring = '\0';
		return (newstring);
	}
	newstring = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!newstring)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		newstring[i++] = s1[j++];
	j = 0;
	while (s2[j])
		newstring[i++] = s2[j++];
	newstring[i] = '\0';
	return (newstring);
}
