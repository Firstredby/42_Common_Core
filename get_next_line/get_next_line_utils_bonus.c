/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:49:21 by ishchyro          #+#    #+#             */
/*   Updated: 2024/10/16 14:29:14 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
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

void	erase(t_list **list, char *buf, t_list *newlst)
{
	t_list	*begin;

	if (!*list)
		return ;
	while (*list)
	{
		begin = (*list)->next;
		free((*list)->str);
		free(*list);
		*list = begin;
	}
	*list = NULL;
	if (newlst->str[0])
		*list = newlst;
	else
	{
		free(newlst);
		free(buf);
	}
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
		return ;
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(new));
	last = ft_lstlast(*list);
	i = 0;
	j = 0;
	while (last->str[i] != '\n' && last->str[i] != '\0')
		i++;
	while (last->str[i++])
		buf[j++] = last->str[i];
	buf[j] = '\0';
	new->str = buf;
	new->next = NULL;
	erase(list, buf, new);
}
