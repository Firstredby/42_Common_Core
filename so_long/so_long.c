/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:09:13 by ishchyro          #+#    #+#             */
/*   Updated: 2025/03/09 22:25:57 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checknl(char *map)
{
	int	i;

	i = 0;
	if (!map || !*map)
		return (1);
	if (map[0] == '\n' || map[ft_strlen(map) - 1] == '\n')
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
	return (0);
}

void	clear_all(t_data *data, int code)
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
		(mlx_destroy_display(data->mlx_ptr), free(data->mlx_ptr));
		data->mlx_ptr = NULL;
	}
	exit(code);
}

void	free_map(char **map)
{
	char	**ptr;

	ptr = map;
	while (*ptr)
	{
		if (*ptr != NULL)
		{
			free(*ptr);
			*ptr = NULL;
		}
		ptr++;
	}
	free(map);
	map = NULL;
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
		return (ft_putstr_fd("wrong parameters!\n", 2), 1);
	if (ft_strlen(ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]))) > 4
		|| !ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		return (ft_putstr_fd("Wrong map!\n", 2), 1);
	data.fd = open(argv[1], O_RDONLY);
	if (data.fd < 0)
		return (ft_putstr_fd("Error\n", 2), 1);
	raw_map = get_next_line(data.fd);
	if (!raw_map)
		return (close(data.fd), ft_putstr_fd("Malloc error T_T\n", 2), 1);
	map.map = ft_split(raw_map, '\n');
	if (!map.map)
		return (close(data.fd), free(raw_map), 1);
	seekpos(&map);
	if (checknl(raw_map) || !map_validator(&map))
		return (close(data.fd), free(raw_map), free_map(map.map),
			ft_putstr_fd("Incorrect map!\n", 2), 1);
	return (free(raw_map), create_map(&map, &data), 0);
}
