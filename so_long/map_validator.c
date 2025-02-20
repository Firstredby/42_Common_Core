/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:11:05 by ishchyro          #+#    #+#             */
/*   Updated: 2025/02/20 18:29:53 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	flood_fill(t_point size, t_point current, struct datamap map, char	**map_copy)
{
	static int	coins;
	static int	exit;

	if ((current.y < 0) || (current.x < 0) || (current.y >= size.y)
		|| (current.x >= size.x) || map_copy[current.x][current.y] == '1'
		|| map_copy[current.x][current.y] == '*')
		return (0);
	if (map_copy[current.x][current.y] == 'E')
		exit++;
	if (map_copy[current.x][current.y] == 'C')
		coins++;
	map_copy[current.x][current.y] = '*';
	flood_fill(size, (t_point){current.x - 1, current.y}, map, map_copy);
	flood_fill(size, (t_point){current.x + 1, current.y}, map, map_copy);
	flood_fill(size, (t_point){current.x, current.y - 1}, map, map_copy);
	flood_fill(size, (t_point){current.x, current.y + 1}, map, map_copy);
	return (coins == map.C && exit == map.E);
}

int map_passability(struct datamap map)
{
	t_point	map_size;
	t_point	begin;
	char	**map_copy;
	int		i;

	i = map.mapH;
	map_size.x = map.mapH;
	map_size.y = map.mapW;
	begin.x = map.playerposx;
	begin.y = map.playerposy;
	map_copy = malloc(sizeof(char *) * i + 1);
	map_copy[i + 1] = NULL;
	while(i-- && map.map[i])
		map_copy[i] = ft_strdup(map.map[i]);
	i = flood_fill(map_size, begin, map, map_copy);
	return(free_map(map_copy), i);
}

int	border_check(struct datamap *map)
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
	map->mapH = i;
	map->mapW = j;
	while (j >= 0 && map->map[i - 1][j - 1] == '1')
		j--;
	while (i > 0 && map->map[i - 1][j] == '1')
		i--;
	return (j == 0 && i == 0);
}

int content_check(struct datamap *map)
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
				map->C++;
			if (map->map[i][j] == 'E')
				map->E++;
			if (map->map[i][j] == 'P')
			{
				map->P++;
				map->playerposx = i;
				map->playerposy = j;
			}
			j++;
		}
		i++;
	}
	return (map->C >= 1 && map->E == 1 && map->P == 1);
}

int map_validator(struct datamap *map)
{	
	map->C = 0;
	map->E = 0;
	map->P = 0;
	return (border_check(map) && content_check(map) && map_passability(*map));
}