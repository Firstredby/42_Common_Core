/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:49:21 by ishchyro          #+#    #+#             */
/*   Updated: 2025/03/20 08:48:31 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	big_red_button(t_list **list)
{
	t_list	*begin;

	if (!list || !*list)
		return ;
	while (*list)
	{
		begin = (*list)->next;
		free((*list)->str);
		(*list)->str = NULL;
		free(*list);
		*list = begin;
	}
	*list = NULL;
}

int	str_len(t_list *list)
{
	long int	i;
	long int	len;

	len = 0;
	while (list)
	{
		i = 0;
		while (list->str[i])
		{
			if (list->str[i] == '\0')
				return (++len);
			i++;
			len++;
		}
		list = list->next;
	}
	return (len);
}

void	str_cpy(t_list *list, char *line)
{
	int	i;
	int	j;

	j = 0;
	while (list)
	{
		i = 0;
		while (list->str[i])
			line[j++] = list->str[i++];
		list = list->next;
	}
	line[j] = '\0';
}
