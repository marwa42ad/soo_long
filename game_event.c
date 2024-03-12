/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoham <marmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:08:16 by marmoham          #+#    #+#             */
/*   Updated: 2023/10/11 11:57:51 by marmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_image(t_game	*img)
{
	if (img->floor.img)
		mlx_destroy_image(img->mlx_pointer, img->floor.img);
	if (img->collectable.img)
		mlx_destroy_image(img->mlx_pointer, img->collectable.img);
	if (img->exit.img)
		mlx_destroy_image(img->mlx_pointer, img->exit.img);
	if (img->wall.img)
		mlx_destroy_image(img->mlx_pointer, img->wall.img);
	if (img->player.img)
		mlx_destroy_image(img->mlx_pointer, img->player.img);
}

int	ft_exit(t_game *game)
{
	mlx_clear_window(game->mlx_pointer, game->win_pointer);
	mlx_destroy_window(game->mlx_pointer, game->win_pointer);
	free_map(game->map.map_data);
	destroy_image(game);
	exit(0);
	return (0);
}

void	ft_game_event(t_game *game)
{
	game->steps = 0;
	mlx_hook(game->win_pointer, 2, 1L << 0, movement_work, game);
	mlx_hook(game->win_pointer, 17, 0L, ft_exit, game);
	mlx_loop(game->mlx_pointer);
}
