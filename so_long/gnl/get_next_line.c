/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:49:25 by ishchyro          #+#    #+#             */
/*   Updated: 2025/02/11 15:28:36 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
			if (list->str[i] == '\0')
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
		addline(list, buf);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (big_red_button(&list), NULL);
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

// #include <stdio.h>
// #include <fcntl.h>
// #include <sys/stat.h>

// int main()
// {
// 	char *line;
// 	int fd = open("multiple_nl.txt", O_RDONLY);
// 	while ((line = get_next_line(fd)))
// 	{
// 		printf("%s\n", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }