/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:05:30 by ishchyro          #+#    #+#             */
/*   Updated: 2025/03/04 14:13:01 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	correct_move(int x, int y, char **map)
{
	return (map[x][y] != '1');
}

void	tile_check(int x, int y, t_data *data)
{
	if (data->map->exitposx && data->map->exitposy
		&& data->map->map[data->map->exitposx][data->map->exitposy] != 'P')
		data->map->map[data->map->exitposx][data->map->exitposy] = 'E';
	if (data->map->map[x][y] == 'C')
		data->map->coin--;
}

void	finish_game(t_data *data)
{
	if (!data->map->coin
		&& data->map->exitposx == data->map->playerposx
		&& data->map->exitposy == data->map->playerposy)
		clear_all(data, 0);
}
