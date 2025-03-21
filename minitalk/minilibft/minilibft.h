/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibft.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:33:34 by ishchyro          #+#    #+#             */
/*   Updated: 2025/01/05 15:10:50 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBFT_H
# define MINILIBFT_H

# include <unistd.h>
# include <stdarg.h>

int		ft_atoi(const char *nptr);
int		ft_printf(const char *string, ...);
void	ft_putchar_fd(char c, int fd);
int		parser(char c, va_list list);
int		singchr(char c);
int		string(char *str);
int		integer(int num);
int		vpointer(unsigned long long addr);
int		unsint(unsigned int num);
int		hexprint(unsigned long long addr, char c);
void	hexfound(unsigned long long addr, char chr);
int		percent(void);

#endif
