/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:49:21 by ishchyro          #+#    #+#             */
/*   Updated: 2024/10/05 17:59:07 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*arr;
	unsigned int	i;

	if (!nmemb || !size)
		return (NULL);
	if (4294967295 / nmemb < size)
		return (NULL);
	arr = malloc(size * nmemb);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		arr[i] = 0;
		i++;
	}
	return ((void *)arr);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int str_len(t_list *list)
{
	int i;
	int len;

	len = 0;
	while (list)
	{
		i = 0;
		while (list->str[i])
		{
			if (list->str[i++] == '\n')
			{
				len++;
				return (len);
			}
			len++;
		}
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
				return ;
			}
			line[j++] = list->str[i++];
		}
		list = list->next;
	}
}

void	erase(t_list **list, char *buf, t_list *new)
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
	if (new->str[0])
		*list = new;
	else
	{
		free(new);
		free(buf);
	}
}

void	list_clear(t_list **list)
{
	t_list	*last;
	t_list	*new;
	char	*buf;
	int		i;
	int		j;

	new = malloc(sizeof(t_list));
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!new || !buf)
		return ;
	last = ft_lstlast(*list);
	i = 0;
	j = 0;
	while (last->str[i] != '\n' && last->str[i] != '\0')
		i++;
	while (last->str[i++])
		buf[j++] = last->str[i];
	new->str = buf;
	new->next = NULL;
	erase(list, buf, new);
}
