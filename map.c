/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwamostafa <marwamostafa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:22:31 by marmoham          #+#    #+#             */
/*   Updated: 2023/12/29 14:00:02 by marwamostaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_row(char *argv)
{
	char	*line;
	int		row;
	int		fd;

	row = 0;
	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		row++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (row);
}

int	str_cmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	**create_map(char *script_map, t_map *game)
{
	char	*line;
	int		i;
	//int		j;
	int		fd;

	i = 0;
	//j = 0;
	fd = open(script_map, O_RDONLY);
	game->size.row = get_row(script_map);
	game->map_data = ft_calloc(sizeof(char *), (game->size.row + 1));
	if (!game->map_data)
		return (free (game->map_data), NULL);
	line = get_next_line(fd);
	while (line)
	{
		if (str_cmp("\n", line) == 0)
			return (free(line), NULL);
		game->map_data[i++] = ft_strtrim(line, "\n");
		free(line);
		line = get_next_line(fd);
	}
	game->map_data[i] = NULL;
	close(fd);
	game->size.col = ft_strlen(game->map_data[0]);
	return (game->map_data);
}
