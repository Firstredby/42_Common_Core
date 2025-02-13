/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:09:13 by ishchyro          #+#    #+#             */
/*   Updated: 2025/02/11 20:48:29 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	border_check(char **split_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (split_map[i][j] == '1')
		j++;
	while (split_map[i] && split_map[i][j - 1] == '1')
		i++;
	if ((j < 3 || i < 3)
		|| (i == 3 && j == 3)
		|| (j > 59 || i > 29))
		return (0);
	while (j >= 0 && split_map[i - 1][j - 1] == '1')
		j--;
	while (i > 0 && split_map[i - 1][j] == '1')
		i--;
	return (j == 0 && i == 0);
}

int content_check(char **split_map, struct datamap *map)
{
	int	i;
	int	j;

	i = 1;
	while (split_map[i][1] != '1')
	{
		j = 1;
		while (split_map[i][j] != '1')
		{
			if (split_map[i][j] == 'C')
				map->C++;
			if (split_map[i][j] == 'E')
				map->E++;
			if (split_map[i][j] == 'P')
				map->P++;
			j++;
		}
		i++;
	}
	return (map->C >= 1 && map->E == 1 && map->P == 1);
}

int map_validator(char **split_map)
{
	struct datamap map;
	
	map.C = 0;
	map.E = 0;
	map.P = 0;
	return (border_check(split_map) && content_check(split_map, &map));
}

void	free_map(char **split_map)
{
    int** ptr;

	ptr = split_map;
    while (*ptr != NULL) {
        free(*ptr);
        ptr++;
    }
    free(split_map);
}

int main(int argc, char **argv)
{
	char *map;
	char **split_map;

	if (argc != 2)
		return (ft_putstr_fd("wrong parameters!\n", 2), 0);
	int fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("Error\n", 2), 0);
	map = get_next_line(fd);
	split_map = ft_split(map, '\n');
	if (map_validator(split_map))
		write(1, "OK", 2);
	else
		write(1, "KO", 2);
	return (close(fd), free(map), free_map(split_map), 0);
}