/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:12:38 by ishchyro          #+#    #+#             */
/*   Updated: 2024/12/21 07:17:07 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i + 1);
}

static int	counter(char const *s, char c)
{
	int	i;
	int	count;
	int	check;

	i = 0;
	count = 0;
	check = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		if (s[i++] == c)
			check++;
	}
	if (check == (int)ft_strlen(s))
		return (0);
	if (!count)
		count++;
	return (count);
}

static void	eraser(char **list, int i)
{
	while (--i >= 0)
		free(list[i]);
	free(list);
}

static char	**main_func(char const *s, char c, char **split_list)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < counter(s, c))
	{
		j = 0;
		while (*str == c)
			str++;
		split_list[i] = ft_calloc(sizeof(char), word(str, c));
		if (!split_list[i])
			return (eraser(split_list, i), NULL);
		while (*str != c && *str != '\0')
		{
			split_list[i][j++] = *str;
			str++;
		}
		i++;
	}
	return (split_list);
}

char	**ft_split(char const *s, char c)
{
	char	**split_list;

	split_list = ft_calloc(sizeof(char *), (counter(s, c) + 1));
	if (!split_list || !s)
		return (NULL);
	return (main_func(s, c, split_list));
}
