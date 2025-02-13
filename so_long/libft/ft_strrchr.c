/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:13:37 by ishchyro          #+#    #+#             */
/*   Updated: 2024/12/21 06:28:41 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const	char *s, int c)
{
	int		i;
	int		cp;
	char	*str;
	int		check;

	i = 0;
	check = 0;
	str = (char *)s;
	while (str[i])
	{
		if (str[i++] == (char)c)
		{
			check = 1;
			cp = i - 1;
		}
	}
	if ((char)c == '\0')
		return (str + i);
	if (!check && i == (int)ft_strlen(s))
		return (NULL);
	while (cp--)
		str++;
	return (str);
}
