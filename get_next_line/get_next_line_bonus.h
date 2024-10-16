/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:49:28 by ishchyro          #+#    #+#             */
/*   Updated: 2024/10/16 11:07:52 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
t_list	*ft_lstlast(t_list *lst);
void	newlist(t_list **list, int fd);
void	addline(t_list **list, char *buf);
int		nlsearch(t_list *list);
char	*get_line(t_list *list);
void	list_clear(t_list **list);
void	str_cpy(t_list *list, char *line);
int		str_len(t_list *list);
void	erase(t_list **list, char *buf, t_list *newlst);

#endif