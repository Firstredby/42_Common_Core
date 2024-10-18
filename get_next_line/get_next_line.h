/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:10:11 by ishchyro          #+#    #+#             */
/*   Updated: 2024/10/18 16:19:10 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
void	big_red_button(t_list **list);
void	newlist(t_list **list, int fd);
void	addline(t_list **list, char *buf);
int		nlsearch(t_list *list);
char	*get_line1(t_list *list);
void	list_cleaning(t_list **list);
void	str_cpy(t_list *list, char *line);
int		str_len(t_list *list);
void	erase(t_list **list, char *buf, t_list *new);

#endif