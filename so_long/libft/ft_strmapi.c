/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 21:31:29 by ishchyro          #+#    #+#             */
/*   Updated: 2024/12/21 07:27:59 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s_cpy;
	char	*str;
	int		i;

	str = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	s_cpy = (char *)s;
	i = 0;
	while (s[i++] && str)
		str[i - 1] = f(i - 1, s_cpy[i - 1]);
	return (str);
}
