/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwamostafa <marwamostafa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:41:58 by marmoham          #+#    #+#             */
/*   Updated: 2023/12/29 19:56:53 by marwamostaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	game->mlx_pointer = mlx_init();
	if (!game->mlx_pointer)
	{
		free(game->mlx_pointer);
		ft_putstr_fd("ERROR", 2);
		free_map(game->map.map_data);
	}
	game->win_pointer = mlx_new_window(game->mlx_pointer, \
	game->map.size.col * 32, game->map.size.row * 32, "so_long");
	if (!game->win_pointer)
	{
		mlx_destroy_window(game->mlx_pointer, game->win_pointer);
		ft_putstr_fd("ERRR", 2);
		free_map(game->map.map_data);
	}
	create_images_in_game(game);
	draw_image(game);
}

int	main(int ac, char **av)
{
	t_map	map_data;
	t_game	game;

	if (is_valid_file(ac, av) != 0)
		return (1);
	if (create_map(av[1], &map_data) == NULL)
		return (ft_putstr_fd("Map is not valid\n", 2), exit(1), 1);
	else
		check_map_format(&map_data, av[1]);
	game.map = map_data;
	init_game(&game);
	ft_game_event(&game);
	free(game.map.ar_coll);
	free_map(game.map.map_data);
	free(&map_data);
	return (0);
}
