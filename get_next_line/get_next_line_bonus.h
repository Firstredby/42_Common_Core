/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:49:28 by ishchyro          #+#    #+#             */
/*   Updated: 2024/10/18 16:33:37 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*str;
	int				fd;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
void	big_red_button(t_list **list);
void	newlist(t_list **list, int fd);
void	addline(t_list **list, char *buf, int fd);
int		nlsearch(t_list *list);
char	*get_line1(t_list *list);
void	list_cleaning(t_list **list);
void	str_cpy(t_list *list, char *line);
int		str_len(t_list *list);
void	erase(t_list **list, char *buf, t_list *newlst);

#endif