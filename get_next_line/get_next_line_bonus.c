/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:49:25 by ishchyro          #+#    #+#             */
/*   Updated: 2024/10/16 14:32:07 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(t_list *list)
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

void	addline(t_list **list, char *buf)
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

void	newlist(t_list **list, int fd)
{
	int		char_read;
	char	*buf;

// if (!*list || !list)
// {

// }
	while (!nlsearch(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return ;
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read <= 0)
		{
			free(buf);
			return ;
		}
		buf[char_read] = '\0';
		addline(list, buf);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*line;
	static int		fd_check;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	if (fd_check != fd)
	{
		t_list	*tmp;
		while (list)
		{
			tmp = list->next;
			free(list->str);
			free(list);
			list = tmp;
		}
		fd_check = fd;
	}
	newlist(&list, fd);
	if (!list)
		return (NULL);
	line = get_line(list);
	list_cleaning(&list);
	return (line);
}

// #include <stdio.h>
// #include <fcntl.h>
// #include <sys/stat.h>

// int main()
// {
// 	char *line;
// 	int i = 0;
// 	int fd[3] = {open("41_with_nl", O_RDONLY), open("42_with_nl", O_RDONLY), open("43_with_nl", O_RDONLY)};
// 	do 
// 	{
// 		line = get_next_line(fd[i]);
// 		if (!line)
// 		{
// 			close(fd[i]);
// 			i++;
// 		}
// 		else
// 			printf("%s\n", line);
// 		free(line);
// 	} while (i < 3);
// 	close(fd[i]);
// 	return (0);
// }