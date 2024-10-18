/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:49:25 by ishchyro          #+#    #+#             */
/*   Updated: 2024/10/18 16:34:59 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_line1(t_list *list)
{
	char	*line;

	if (!list)
		return (NULL);
	line = malloc(str_len(list) + 1);
	if (!line)
		return (NULL);
	str_cpy(list, line);
	return (line);
}

void	addline(t_list **list, char *buf, int fd)
{
	t_list	*new;
	t_list	*last;

	new = malloc(sizeof(t_list));
	if (!new)
		return (free(buf));
	last = *list;
	while (last && last->next)
		last = last->next;
	if (!last)
		*list = new;
	else
		last->next = new;
	new->str = buf;
	new->fd = fd;
	new->next = NULL;
}

int	nlsearch(t_list *list)
{
	int	i;

	while (list)
	{
		i = 0;
		while (list->str[i] && i < BUFFER_SIZE)
		{
			if (list->str[i] == '\n' || list->str[i] == '\0')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

void	newlist(t_list **list, int fd)
{
	int		char_read;
	char	*buf;

	while (!nlsearch(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return (big_red_button(list));
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read <= 0)
		{
			free(buf);
			return ;
		}
		buf[char_read] = '\0';
		addline(list, buf, fd);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*line;
	t_list			*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (big_red_button(&list), NULL);
	if (list && list->fd != fd)
	{
		while (list)
		{
			tmp = list->next;
			free(list->str);
			free(list);
			list = tmp;
		}
	}
	newlist(&list, fd);
	if (!list)
		return (NULL);
	line = get_line1(list);
	if (line)
		list_cleaning(&list);
	else
		big_red_button(&list);
	return (line);
}
