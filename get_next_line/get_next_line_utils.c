/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:49:21 by ishchyro          #+#    #+#             */
/*   Updated: 2024/10/18 16:33:16 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	big_red_button(t_list **list)
{
	t_list	*begin;

	while (*list)
	{
		begin = (*list)->next;
		free((*list)->str);
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
			if (list->str[i] == '\n')
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
		{
			if (list->str[i] == '\n')
			{
				line[j] = '\n';
				line[j + 1] = '\0';
				return ;
			}
			line[j++] = list->str[i++];
		}
		list = list->next;
	}
	line[j] = '\0';
}

void	erase(t_list **list, char *buf, t_list *new)
{
	if (!*list)
		return ;
	big_red_button(list);
	if (new->str[0])
		*list = new;
	else
		return (free(new), free(buf));
}

void	list_cleaning(t_list **list)
{
	t_list	*last;
	t_list	*new;
	char	*buf;
	int		i;
	int		j;

	new = malloc(sizeof(t_list));
	if (!new)
		return (big_red_button(list));
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(new), big_red_button(list));
	last = *list;
	while (last && last->next)
		last = last->next;
	i = 0;
	j = 0;
	while (last->str[i] != '\n' && last->str[i] != '\0')
		i++;
	while (last->str[i++])
		buf[j++] = last->str[i];
	buf[j] = '\0';
	new->str = buf;
	new->next = NULL;
	return (erase(list, buf, new));
}
