/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:39:58 by ishchyro          #+#    #+#             */
/*   Updated: 2025/02/21 20:49:48 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include <mlx.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define KEY_UP		65362
# define KEY_DOWN	65364
# define KEY_LEFT	65361
# define KEY_RIGHT	65363
# define ESC_KEY	65307

struct s_datamap
{
	char	**map;
	int		exit;
	int		player;
	int		coin;
	int		mapw;
	int		maph;
	int		playerposx;
	int		playerposy;
	int		exitposx;
	int		exitposy;
};

typedef struct s_image
{
	void	*img;
	char	*sprite_path;
	int		img_w;
	int		img_h;
}	t_image;

typedef struct s_data
{
	void				*mlx_ptr;
	void				*win_ptr;
	int					fd;
	struct s_datamap	*map;
	t_image				*img;
}	t_data;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

int		map_validator(struct s_datamap *map);
int		create_map(struct s_datamap *map, t_data *data);
void	fillmap(t_data *data);
int		hook_init(t_data data);
void	moveup(t_data *data);
void	movedown(t_data *data);
void	moveleft(t_data *data);
void	moveright(t_data *data);
int		correct_move(int x, int y, char **map);
void	tile_check(int x, int y, t_data *data);
void	finish_game(t_data *data);
void	free_map(char **map);
void	clear_all(t_data *data);

#endif