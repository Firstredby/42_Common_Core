/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:03:18 by ishchyro          #+#    #+#             */
/*   Updated: 2024/12/12 08:54:37 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list // modified for push_swap
{
	char			*value;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

int		ft_atoi(const char *nptr);
void	ft_bzero(char *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_isdigit(int c);
char	*ft_itoa(int n);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list *lst);
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *str);

// Printf functions
int		ft_printf(const char *string, ...);
int		parser(char c, va_list list);
int		singchr(char c);
int		string(char *str);
int		integer(int num);
int		vpointer(unsigned long long addr);
int		unsint(unsigned int num);
int		hexprint(unsigned long long addr, char c);
void	hexfound(unsigned long long addr, char chr);
int		percent(void);
#endif  //LIBFT_H