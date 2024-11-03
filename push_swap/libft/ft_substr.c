/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:17:17 by ishchyro          #+#    #+#             */
/*   Updated: 2024/09/18 19:21:09 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "string.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*substr;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		substr = ft_calloc(1, 1);
		if (!substr)
			return (NULL);
		*substr = '\0';
		return (substr);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	substr = ft_calloc((len + 1), sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < (int)len)
	{
		substr[i] = (char)s[i + start];
		i++;
	}
	return (substr);
}
