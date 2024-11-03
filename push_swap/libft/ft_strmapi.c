/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 21:31:29 by ishchyro          #+#    #+#             */
/*   Updated: 2024/09/12 17:11:00 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s_cpy;
	char	*str;
	int		i;

	str = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	s_cpy = (char *)s;
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s_cpy[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
