/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:09:13 by ishchyro          #+#    #+#             */
/*   Updated: 2025/02/20 19:00:17 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checknl(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	clear_all(t_data *data)
{
	free_map(data->map->map);
	mlx_destroy_image(data->mlx_ptr, data->img->img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(-1);
}

void	free_map(char **map)
{
    char** ptr;

	ptr = map;
    while (*ptr) {
        free(*ptr);
        ptr++;
    }
    free(map);
}

int main(int argc, char **argv)
{
	char			*raw_map;
	struct datamap	s_map;
	t_data			data;

	if (argc != 2)
		return (ft_putstr_fd("wrong parameters!\n", 2), 0);
	data.fd = open(argv[1], O_RDONLY);
	if (data.fd < 0)
		return (ft_putstr_fd("Error\n", 2), 0);
	raw_map = get_next_line(data.fd);
	close(data.fd);
	if (!raw_map || checknl(raw_map))
		return (free(raw_map), 0);
	s_map.map = ft_split(raw_map, '\n');
	if (!s_map.map)
		return (free(raw_map), 0);
	free(raw_map);
	if (!map_validator(&s_map))
		return (free_map(s_map.map), write(1, "KO", 2), -1);
	create_map(&s_map, &data);
	return (free_map(s_map.map), 0);
}
