/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoham <marmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:20:54 by marmoham          #+#    #+#             */
/*   Updated: 2023/10/12 10:14:54 by marmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangular(t_map game)
{
	int	i;

	i = 1;
	while (i < game.size.row)
	{
		if (ft_strlen(game.map_data[i]) != ft_strlen(game.map_data[i - 1]))
		{
			ft_putstr_fd("Map is not rectangular\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

int	valid_character(t_map *game)
{
	int	i;
	int	k;

	i = 0;
	while (i < game->size.row)
	{
		k = 0;
		while (k < game->size.col)
		{
			if (game->map_data[i][k] != '0' && game->map_data[i][k] != '1' && \
			game->map_data[i][k] != 'C' && game->map_data[i][k] != 'E' && \
			game->map_data[i][k] != 'P' && game->map_data[i][k] != '\n')
			{
				ft_putstr_fd("invaled character in map\n", 2);
				return (1);
			}
			k++;
		}
		i++;
	}
	return (0);
}

int	count_char(t_map *game, char c)
{
	int	i;
	int	j;
	int	o;
	int	count;

	i = 0;
	o = 0;
	count = 0;
	while (i < (game)->size.row)
	{
		j = ft_strspn(game->map_data[i], c);
		if (j != 0)
		{
			o = ft_strchar(game->map_data[i], c);
			count = count + j;
			if (c == 'E')
				game->end = (t_point){i, o};
			if (c == 'P')
				game->start = (t_point){i, o};
		}
		i++;
	}
	if (c == 'C')
		game->c = count;
	return (count);
}

int	check_duplicates(t_map *game)
{
	int	nb_exit;
	int	nb_entry;
	int	nb_coll;

	nb_exit = count_char(game, 'E');
	nb_entry = count_char(game, 'P');
	nb_coll = count_char(game, 'C');
	if (!(nb_exit == 1 && nb_entry == 1 && nb_coll > 0))
	{
		ft_putstr_fd("invalid Number of exit or collectible or player\n", 1);
		return (1);
	}
	return (0);
}

void	check_map_format(t_map *game, char *argv)
{
	(void)argv;
	if (is_rectangular(*game) != 0)
		free_and_exit(game);
	if (check_duplicates(game) != 0)
		free_and_exit(game);
	if (is_closed_map(*game) != 0)
		free_and_exit(game);
	if (valid_character(game) != 0)
		free_and_exit(game);
	if (find_total_collec(game, game->c) != 0)
		free_and_exit(game);
	if (check_path(*game, argv) != 0)
		free_and_exit(game);
}
