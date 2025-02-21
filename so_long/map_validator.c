/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:11:05 by ishchyro          #+#    #+#             */
/*   Updated: 2025/02/21 20:50:43 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	flood_fill(t_point size, t_point curr, struct s_datamap map, char	**m_cpy)
{
	static int	coins;
	static int	exit;

	if ((curr.y < 0) || (curr.x < 0) || (curr.y >= size.y)
		|| (curr.x >= size.x) || m_cpy[curr.x][curr.y] == '1'
		|| m_cpy[curr.x][curr.y] == '*')
		return (0);
	if (m_cpy[curr.x][curr.y] == 'E')
		exit++;
	if (m_cpy[curr.x][curr.y] == 'C')
		coins++;
	m_cpy[curr.x][curr.y] = '*';
	flood_fill(size, (t_point){curr.x - 1, curr.y}, map, m_cpy);
	flood_fill(size, (t_point){curr.x + 1, curr.y}, map, m_cpy);
	flood_fill(size, (t_point){curr.x, curr.y - 1}, map, m_cpy);
	flood_fill(size, (t_point){curr.x, curr.y + 1}, map, m_cpy);
	return (coins == map.coin && exit == map.exit);
}

int	map_passability(struct s_datamap map)
{
	t_point	map_size;
	t_point	begin;
	char	**map_copy;
	int		i;

	i = map.maph;
	map_size.x = map.maph;
	map_size.y = map.mapw;
	begin.x = map.playerposx;
	begin.y = map.playerposy;
	map_copy = malloc(sizeof(char *) * i + 1);
	map_copy[i + 1] = NULL;
	while (i-- && map.map[i])
		map_copy[i] = ft_strdup(map.map[i]);
	i = flood_fill(map_size, begin, map, map_copy);
	return (free_map(map_copy), i);
}

int	border_check(struct s_datamap *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map[i][j] == '1')
		j++;
	while (map->map[i] && map->map[i][j - 1] == '1')
		i++;
	if ((j < 3 || i < 3)
		|| (i == 3 && j == 3)
		|| (j > 80 || i > 45))
		return (0);
	map->maph = i;
	map->mapw = j;
	while (j >= 0 && map->map[i - 1][j - 1] == '1')
		j--;
	while (i > 0 && map->map[i - 1][j] == '1')
		i--;
	return (j == 0 && i == 0);
}

int	content_check(struct s_datamap *map)
{
	int	i;
	int	j;

	i = 1;
	while (map->map[i])
	{
		j = 1;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'C')
				map->coin++;
			if (map->map[i][j] == 'E')
				map->exit++;
			if (map->map[i][j] == 'P')
				map->player++;
			j++;
		}
		i++;
	}
	return (map->coin >= 1 && map->exit == 1 && map->player == 1);
}

int	map_validator(struct s_datamap *map)
{
	map->coin = 0;
	map->exit = 0;
	map->player = 0;
	return (border_check(map) && content_check(map) && map_passability(*map));
}
