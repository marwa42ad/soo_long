/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwamostafa <marwamostafa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:32:28 by marmoham          #+#    #+#             */
/*   Updated: 2023/12/29 14:03:32 by marwamostaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_end_game(t_game *game)
{
	if (game->map.c == 0)
	{
		ft_putstr_fd("\nYou Have Won, Congrats!\nYOU take \n", 1);
		ft_putnbr_fd(game->steps, 1);
		ft_putstr_fd(" steps\n", 1);
		ft_exit(game);
	}
	else
	{
		ft_putstr_fd("\nYou need to collect :", 1);
		ft_putnbr_fd(game->map.c, 1);
	}
}

int	valid_move(t_game *game, int x, int y)
{
	if (game->map.map_data[game->map.start.row + y]
		[game->map.start.col + x] == 'E')
	{
		check_end_game(game);
	}
	else
	{
		if (game->map.map_data[game->map.start.row + y]
			[game->map.start.col + x] == '0')
		{
			game->map.map_data[game->map.start.row][game->map.start.col] = '0';
		}
		if (game->map.map_data[game->map.start.row + y]
			[game->map.start.col + x] == 'C')
		{
			game->map.map_data[game->map.start.row][game->map.start.col] = '0';
			game->map.c--;
		}
		game->map.map_data[game->map.start.row + y]
		[game->map.start.col + x] = 'P';
		game->map.start.col += x;
		game->map.start.row += y;
		game->steps++;
	}
	return (0);
}

int	keyhandle_w_s(t_game *game, int movement)
{
	int	i;
	int	j;
	int	k;

	i = game->map.start.col;
	j = game->map.start.row;
	if (movement == 13 || movement == UP)
	{
		j--;
		if (game->map.map_data[j][i] == '1')
			return (1);
		k = valid_move(game, 0, -1);
		if (!k)
			return (1);
	}
	else if (movement == 1 || movement == DOWN)
	{
		j++;
		if (game->map.map_data[j][i] == '1')
			return (1);
		k = valid_move(game, 0, 1);
		if (!k)
			return (1);
	}
	return (0);
}

int	keyhandle_a_d(t_game *game, int movement)
{
	int	i;
	int	j;
	int	k;

	i = game->map.start.col;
	j = game->map.start.row;
	if (movement == 0 || movement == LEFT)
	{
		i--;
		if (game->map.map_data[j][i] == '1')
			return (1);
		k = valid_move(game, -1, 0);
		if (!k)
			return (1);
	}
	else if (movement == 2 || movement == RIGHT)
	{
		i++;
		if (game->map.map_data[j][i] == '1')
			return (1);
		k = valid_move(game, 1, 0);
		if (!k)
			return (1);
	}
	return (0);
}

int	movement_work(int command, t_game *game)
{
	int	move;
	
	if (command == 53 || command == ESC)
		ft_exit(game);
	else if (command == 13 || command == UP)
		move = keyhandle_w_s(game, command);
	else if (command == 1 || command == DOWN)
		move = keyhandle_w_s(game, command);
	else if (command == 0 || command == RIGHT)
		move = keyhandle_a_d(game, command);
	else if (command == 2 || command == LEFT)
		move = keyhandle_a_d(game, command);
	mlx_clear_window(game->mlx_pointer, game->win_pointer);
	draw_image(game);
	ft_putstr_fd("\nSteps Taken: ", 1);
	ft_putnbr_fd(game->steps, 1);
	ft_putstr_fd("\nCollectables remaining: ", 1);
	ft_putnbr_fd(game->map.c, 1);
	return (0);
}
