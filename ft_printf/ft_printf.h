/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:33:34 by ishchyro          #+#    #+#             */
/*   Updated: 2024/09/25 17:45:56 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ft_printf.h

# include "./libft.h"
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *string, ...);
int	parser();
int	singchr(char c);
int	string(char *str);
int	integer(int num);
int	vpointer(void *str);
int	unsint(unsigned int num);

#endif