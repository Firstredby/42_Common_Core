/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:49:25 by ishchyro          #+#    #+#             */
/*   Updated: 2024/10/19 18:07:37 by ishchyro         ###   ########.fr       */
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

void	addline(t_list *list[], char *buf)
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

void	newlist(t_list *list[], int fd)
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
			if (char_read < 0)
				big_red_button(list);
			return ;
		}
		buf[char_read] = '\0';
		addline(list, buf);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list[1025];
	char			*line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (big_red_button(&list[fd]), NULL);
	newlist(&list[fd], fd);
	if (!list[fd])
		return (NULL);
	line = get_line1(list[fd]);
	if (line)
		list_cleaning(&list[fd]);
	else
		big_red_button(&list[fd]);
	return (line);
}
