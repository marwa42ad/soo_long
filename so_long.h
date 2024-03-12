/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoham <marmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:07:51 by marmoham          #+#    #+#             */
/*   Updated: 2023/10/12 12:02:11 by marmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "minilibx/mlx.h"

# define PLAYER_TRACK "./textures/player.xpm"
# define WALL_TRACK "./textures/wall.xpm"
# define COLLECTABLE_TRACK "./textures/mashroom.xpm"
# define EXITE_TRACK "./textures/exit.xpm"
# define FLOOR_TRACK "./textures/floor.xpm"

# define ESC        53
# define UP         126
# define DOWN       125
# define LEFT       123
# define RIGHT      124
# define BUFF_SIZE  1

typedef struct s_point
{
	int							row;
	int							col;
}								t_point;

typedef struct s_map
{
	t_point			size;
	t_point			start;
	t_point			end;
	int				c;
	t_point			*ar_coll;
	char			**map_data;
}				t_map;

typedef struct s_img
{
	void		*img;
	int			width;
	int			height;
}					t_img;

typedef struct s_game
{
	struct s_map	map;
	void			*mlx_pointer;
	void			*win_pointer;
	int				steps;
	t_img			player;
	t_img			collectable;
	t_img			exit;
	t_img			wall;
	t_img			floor;
}				t_game;

int		is_rectangular(t_map map);
int		check_duplicates(t_map *game);
int		valid_character(t_map *game);
int		is_closed_map(t_map map);
int		count_char(t_map *game, char c);
void	check_map_format(t_map *game, char *argv);
char	**create_map(char *script_map, t_map *game);
int		is_empty_file(char *map);
void	ft_free_map(char **map);
int		check_extension(const char *fn);
int		is_valid_file(int ac, char **av);
int		find_total_collec(t_map *game, int c);
int		get_row(char *argv);
void	flood_map(char **tab, t_point size, t_point cur, char to_fill);
int		check_path(t_map mp, char *av);
int		ft_strspn(const char *s, char c);
int		ft_strchar(const char *s, int c);
int		str_cmp(char *s1, char *s2);
void	free_map(char **map);
int		valid_move(t_game *game, int x, int y);
int		keyhandle_w_s(t_game *game, int movement);
int		keyhandle_a_d(t_game *game, int movement);
int		movement_work(int command, t_game *game);
t_img	load_image(void *mlx, char *track);
void	create_images_in_game(t_game *game);
void	add_images_in_game(char c, int x, int y, t_game game);
void	draw_image(t_game *game);
void	init_game(t_game *game);
void	destroy_image(t_game	*img);
int		ft_exit(t_game *game);
void	ft_game_event(t_game *game);
void	free_and_exit(t_map *game);
void	check_end_game(t_game *game);
int		check_collectable_path(t_map m, char	**tmp_map);
#endif
