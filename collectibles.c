/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoham <marmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:28:33 by marmoham          #+#    #+#             */
/*   Updated: 2023/10/12 09:57:21 by marmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_total_collec(t_map *game, int c)
{
	int		k;
	int		i;
	int		o;
	t_point	*collect;

	k = 0;
	i = 0;
	collect = ft_calloc(sizeof(t_point), c);
	if (!collect)
	{
		ft_putstr_fd("Error\n", 1);
		return (1);
	}
	while (i < game->size.row)
	{
		o = 0;
		while (o++ < game->size.col)
		{
			if (game->map_data[i][o] == 'C')
				collect[k++] = (t_point){i, o};
		}
		i++;
	}
	game->ar_coll = collect;
	return (0);
}
