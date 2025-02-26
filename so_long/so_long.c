/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:09:13 by ishchyro          #+#    #+#             */
/*   Updated: 2025/02/25 16:58:00 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checknl(char *map)
{
	int	i;

	i = 0;
	if (map[i] == '\n')
		return (1);
	while (map[i])
	{
		if ((map[i] == '\n' && map[i + 1] == '\n'))
			return (1);
		if (!(map[i] == 'P' || map[i] == 'E' || map[i] == 'C'
				|| map[i] == '0' || map[i] == '1' || map[i] == '\n'))
			return (1);
		i++;
	}
	if (map[i - 1] == '\n')
		return (1);
	return (0);
}

void	clear_all(t_data *data)
{
	int	i;

	i = 0;
	close(data->fd);
	free_map(data->map->map);
	while (i < 5)
	{
		if (data->img[i].img && data->mlx_ptr)
		{
			mlx_destroy_image(data->mlx_ptr, data->img[i].img);
			data->img[i].img = NULL;
		}
		i++;
	}
	if (data->win_ptr)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	exit(-1);
}

void	free_map(char **map)
{
	char	**ptr;

	ptr = map;
	while (*ptr)
	{
		free(*ptr);
		ptr++;
	}
	free(map);
}

void	seekpos(struct s_datamap *map)
{
	int	i;
	int	j;

	i = 1;
	while (map->map[i])
	{
		j = 1;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'E')
			{
				map->exitposx = i;
				map->exitposy = j;
			}
			if (map->map[i][j] == 'P')
			{
				map->playerposx = i;
				map->playerposy = j;
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	char				*raw_map;
	struct s_datamap	map;
	t_data				data;

	if (argc != 2)
		return (ft_putstr_fd("wrong parameters!\n", 2), 0);
	if (ft_strlen(ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]))) > 4
		|| !ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]))
		|| ft_strlen(argv[1]) < 5)
		return (ft_putstr_fd("Wrong map!\n", 2), 0);
	data.fd = open(argv[1], O_RDONLY);
	if (data.fd < 0)
		return (ft_putstr_fd("Error\n", 2), 0);
	raw_map = get_next_line(data.fd);
	if (!raw_map)
		return (ft_putstr_fd("Malloc error T_T\n", 2), free(raw_map), 0);
	map.map = ft_split(raw_map, '\n');
	if (!map.map)
		return (close(data.fd), free(raw_map), 0);
	seekpos(&map);
	if (checknl(raw_map) || !map_validator(&map))
		return (free(raw_map), free_map(map.map),
		ft_putstr_fd("Incorrect map!\n", 2), -1);
	free(raw_map);
	return (create_map(&map, &data), 0);
}
