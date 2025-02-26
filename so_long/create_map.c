/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:43:04 by ishchyro          #+#    #+#             */
/*   Updated: 2025/02/25 15:53:13 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_data *data, int i, int j, int sprite)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img[sprite].img, j * 25, i * 25);
}

void	fillmap(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map->map[i])
	{
		j = 0;
		while (data->map->map[i][j])
		{
			if (data->map->map[i][j] == '1')
				put_image(data, i, j, 0);
			else if (data->map->map[i][j] == 'C')
				put_image(data, i, j, 2);
			else if (data->map->map[i][j] == 'P')
				put_image(data, i, j, 3);
			else if (data->map->map[i][j] == 'E')
				put_image(data, i, j, 4);
			else
				put_image(data, i, j, 1);
			j++;
		}
		i++;
	}
}

void	sprite_load(t_data *data)
{
	data->img[0].img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./sprites/1.xpm", &data->img->img_w, &data->img->img_h);
	data->img[1].img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./sprites/2.xpm", &data->img->img_w, &data->img->img_h);
	data->img[2].img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./sprites/3.xpm", &data->img->img_w, &data->img->img_h);
	data->img[3].img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./sprites/4.xpm", &data->img->img_w, &data->img->img_h);
	data->img[4].img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./sprites/5.xpm", &data->img->img_w, &data->img->img_h);
	if (!data->img[0].img || !data->img[1].img || !data->img[2].img
		|| !data->img[3].img || !data->img[4].img)
		return (ft_putstr_fd("Sprite loading error.", 2), clear_all(data));
}

int	create_map(struct s_datamap *map, t_data *data)
{
	t_image	img[5];
	int		width;
	int		height;

	width = map->mapw * 25;
	height = map->maph * 25;
	data->map = map;
	data->img = img;
	data->win_ptr = NULL;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (clear_all(data), 0);
	sprite_load(data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, width, height, "so_long");
	if (!data->win_ptr)
		return (clear_all(data), 0);
	fillmap(data);
	hook_init(*data);
	if (mlx_loop(data->mlx_ptr))
		return (clear_all(data), 0);
	return (clear_all(data), 1);
}
