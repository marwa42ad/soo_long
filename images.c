/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwamostafa <marwamostafa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:43:24 by marmoham          #+#    #+#             */
/*   Updated: 2023/12/30 13:23:03 by marwamostaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	load_image(void *mlx, char *track)
{
	t_img	img;

	//loading an XPM (X PixMap) image file. It takes the MiniLibX context (mlx), 
	//the path to the image file (track), and pointers to variables (&img.height and &img.width) 
	//where it will store the height and width of the loaded image.
	img.img = mlx_xpm_file_to_image(mlx, track, &img.height, &img.width);
	return (img);
}

void	create_images_in_game(t_game *game)
{
	game->wall = load_image(game->mlx_pointer,
			"./textures/wall.xpm");
	game->collectable = load_image(game->mlx_pointer,
			"./textures/mashroom.xpm");
	game->floor = load_image(game->mlx_pointer,
			"./textures/floor.xpm");
	game->exit = load_image(game->mlx_pointer,
			"./textures/exit.xpm");
	game->player = load_image(game->mlx_pointer,
			"./textures/player.xpm");
}

void	add_images_in_game(char c, int x, int y, t_game game)
{
	if (c == 'P')
		mlx_put_image_to_window(game.mlx_pointer, game.win_pointer,
			game.player.img, y * 32, x * 32);
	else if (c == 'C')
		mlx_put_image_to_window(game.mlx_pointer, game.win_pointer,
			game.collectable.img, y * 32, x * 32);
	else if (c == 'E')
		mlx_put_image_to_window(game.mlx_pointer, game.win_pointer,
			game.exit.img, y * 32, x * 32);
	else if (c == '1')
		mlx_put_image_to_window(game.mlx_pointer, game.win_pointer,
			game.wall.img, y * 32, x * 32);//coordinates are calculated based on a grid where each cell is 32x32 pixels.
	else if (c == '0')
		mlx_put_image_to_window(game.mlx_pointer, game.win_pointer,
			game.floor.img, y * 32, x * 32);
	if (!game.wall.img || !game.collectable.img
		|| !game.floor.img || !game.exit.img
		|| !game.player.img)
	{
		mlx_destroy_window(game.mlx_pointer, game.win_pointer);
		destroy_image(&game);
		ft_putstr_fd("Failed to load image", 2);
		free_map(game.map.map_data);
		exit(1);
	}
}

void	draw_image(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map.map_data[++i])
	{
		j = -1;
		while (game->map.map_data[i][++j])
		{
			add_images_in_game('0', i, j, *game);
			add_images_in_game(game->map.map_data[i][j], i, j, *game);
		}
	}
}
