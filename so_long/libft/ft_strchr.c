/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:02:20 by ishchyro          #+#    #+#             */
/*   Updated: 2024/12/21 07:23:15 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const	char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != '\0')
		if (*str == (char)c || !str++)
			return (str);
	if ((char)c == '\0')
		return (str);
	return (NULL);
}
