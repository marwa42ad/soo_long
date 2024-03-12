/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoham <marmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:15:13 by marmoham          #+#    #+#             */
/*   Updated: 2023/10/12 11:10:20 by marmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_closed_map(t_map map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map.size.row)
	{
		j = -1;
		if (map.map_data[i][0] != '1' ||
			map.map_data[i][map.size.col - 1] != '1')
		{
			ft_putstr_fd("Map is not enclosed\n", 2);
			return (1);
		}
		if (i == 0 || i == map.size.row - 1)
		{
			while (map.map_data[i][++j])
			{
				if (map.map_data[i][j] != '1')
					return (ft_putstr_fd("Map is not enclosed\n", 2), 1);
			}
		}
	}
	return (0);
}

void	flood_map(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.col >= size.col || cur.row >= size.row || \
	(tab[cur.row][cur.col] != to_fill && tab[cur.row][cur.col] != 'C'))
		return ;
	tab[cur.row][cur.col] = 'F';
	flood_map(tab, size, (t_point){cur.row - 1, cur.col}, to_fill);
	flood_map(tab, size, (t_point){cur.row + 1, cur.col}, to_fill);
	flood_map(tab, size, (t_point){cur.row, cur.col - 1}, to_fill);
	flood_map(tab, size, (t_point){cur.row, cur.col + 1}, to_fill);
}

int	check_collectable_path(t_map m, char	**tmp_map)
{
	int		i;
	t_point	pos;

	i = 0;
	while (i < m.c)
	{
		pos = m.ar_coll[i];
		if (tmp_map[pos.row - 1][pos.col] != 'F' && tmp_map[pos.row + 1]
			[pos.col] != 'F' && tmp_map[pos.row][pos.col + 1] != 'F' &&
			tmp_map[pos.row][pos.col - 1] != 'F')
		{
			free_map(tmp_map);
			ft_putstr_fd("Player can't reach collectible\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_path(t_map m, char *av)
{
	char	**tmp_map;
	t_map	game;

	tmp_map = create_map(av, &game);
	if (!tmp_map)
		return (1);
	tmp_map[m.start.row][m.start.col] = '0';
	flood_map(tmp_map, m.size, m.start, '0');
	if (tmp_map[m.end.row - 1][m.end.col] != 'F' &&
		tmp_map[m.end.row + 1][m.end.col] != 'F' &&
		tmp_map[m.end.row][m.end.col + 1] != 'F' &&
		tmp_map[m.end.row][m.end.col - 1] != 'F')
	{
		ft_putstr_fd("Player can't reach exit\n", 2);
		free_map(tmp_map);
		return (1);
	}
	if (check_collectable_path(m, tmp_map) == 1)
		return (1);
	free_map(tmp_map);
	return (0);
}
