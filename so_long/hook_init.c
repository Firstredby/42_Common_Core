/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:37:18 by ishchyro          #+#    #+#             */
/*   Updated: 2025/03/04 14:12:48 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy(t_data *data)
{
	return (clear_all(data, 0), 1);
}

int	keypress(int keysym, t_data *data)
{
	if (keysym == 'w' || keysym == KEY_UP)
		moveup(data);
	if (keysym == 'a' || keysym == KEY_LEFT)
		moveleft(data);
	if (keysym == 's' || keysym == KEY_DOWN)
		movedown(data);
	if (keysym == 'd' || keysym == KEY_RIGHT)
		moveright(data);
	if (keysym == ESC_KEY)
		return (destroy(data), 0);
	fillmap(data);
	finish_game(data);
	return (0);
}

int	hook_init(t_data data)
{
	mlx_hook(data.win_ptr, 2, 1L << 0, keypress, &data);
	mlx_hook(data.win_ptr, 17, 1L << 17, destroy, &data);
	return (0);
}
