/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:49:25 by ishchyro          #+#    #+#             */
/*   Updated: 2024/10/08 15:25:27 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(t_list *list)
{
	char	*line;

	if (!list)
		return (NULL);
	line = ft_calloc(str_len(list) + 1, sizeof(char));
	if (!line)
		return (NULL);
	str_cpy(list, line);
	return (line);
}

void addline(t_list **list, char *buf)
{
	t_list *new;
	t_list *last;

	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	last = ft_lstlast(*list);
	if (!last)
		*list = new;
	else
		last->next = new;
	new->str = buf;
	new->next = NULL;
}

int	nlsearch(t_list *list)
{
	int i;

	while (list)
	{
		i = 0;
		while (list->str[i] && i < BUFFER_SIZE)
		{
			if (list->str[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

void newlist(t_list **list, int fd)
{
	int char_read;
	char *buf;

	while(!nlsearch(*list))
	{
		buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buf)
			return ;
		if ((char_read = read(fd, buf, BUFFER_SIZE)) < 0)
		{
			free(buf);
			return ;
		}
		addline(list, buf);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	newlist(&list, fd);
	if(!list)
		return (NULL);
	line = get_line(list);
	list_clear(&list);
	return (line);
}

#include <stdio.h>
#include <fcntl.h>

int main()
{
	char *line;
	int fd = open("empty.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}