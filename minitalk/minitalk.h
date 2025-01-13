/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 12:23:20 by ishchyro          #+#    #+#             */
/*   Updated: 2025/01/13 16:35:45 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define _POSIX_SOURCE
# define _DEFAULT_SOURCE

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include "minilibft/minilibft.h"

void	handler(int sig);
void	msg(int pid, char *str);

#endif
