/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:03:06 by ishchyro          #+#    #+#             */
/*   Updated: 2025/02/21 20:55:03 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moveup(t_data *data)
{
	int	x;
	int	y;

	x = data->map->playerposx;
	y = data->map->playerposy;
	if (!correct_move(x - 1, y, data->map->map))
		return ;
	data->map->map[x][y] = '0';
	tile_check(x - 1, y, data);
	data->map->map[x - 1][y] = 'P';
	data->map->playerposx -= 1;
}

void	movedown(t_data *data)
{
	int	x;
	int	y;

	x = data->map->playerposx;
	y = data->map->playerposy;
	if (!correct_move(x + 1, y, data->map->map))
		return ;
	data->map->map[x][y] = '0';
	tile_check(x + 1, y, data);
	data->map->map[x + 1][y] = 'P';
	data->map->playerposx += 1;
}

void	moveleft(t_data *data)
{
	int	x;
	int	y;

	x = data->map->playerposx;
	y = data->map->playerposy;
	if (!correct_move(x, y - 1, data->map->map))
		return ;
	data->map->map[x][y] = '0';
	tile_check(x, y - 1, data);
	data->map->map[x][y - 1] = 'P';
	data->map->playerposy -= 1;
}

void	moveright(t_data *data)
{
	int	x;
	int	y;

	x = data->map->playerposx;
	y = data->map->playerposy;
	if (!correct_move(x, y + 1, data->map->map))
		return ;
	data->map->map[x][y] = '0';
	tile_check(x, y + 1, data);
	data->map->map[x][y + 1] = 'P';
	data->map->playerposy += 1;
}
