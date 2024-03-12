/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoham <marmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:06:18 by marmoham          #+#    #+#             */
/*   Updated: 2023/10/12 12:08:21 by marmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// void	free_map(char **map)
// {
// 	int	i;

// 	i = 0;
// 	while (map && map[i])
//     {
//         free(map[i]);
// 		i++;
//     }
// 	if (map)
// 	{
// 		free(map);
// 	}
// }

int	check_extension(const char *fn)
{
	int	i;

	i = ft_strlen(fn) - 1;
	if (fn[i] != 'r' || fn[i - 1] != 'e'
		|| fn[i - 2] != 'b'
		|| fn[i - 3] != '.')
	{
		ft_putstr_fd("invaled file extension\n", 2);
		return (1);
	}
	return (0);
}

int	is_empty_file(char *map)
{
	int		fd;
	char	*buf;

	fd = open(map, O_RDONLY);
	if (fd < 0 || read(fd, &buf, 1) < 1)
	{
		ft_putstr_fd("File corrupted\n", 2);
		return (1);
	}
	close(fd);
	return (0);
}

int	is_valid_file(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr_fd("invalid number of arguments\n", 2);
		return (1);
	}
	if (check_extension(av[1]) != 0)
		return (1);
	if (is_empty_file(av[1]) != 0)
		return (1);
	if (is_empty_file(PLAYER_TRACK) != 0)
		return (1);
	if (is_empty_file(EXITE_TRACK) != 0)
		return (1);
	if (is_empty_file(WALL_TRACK) != 0)
		return (1);
	if (is_empty_file(FLOOR_TRACK) != 0)
		return (1);
	if (is_empty_file(COLLECTABLE_TRACK) != 0)
		return (1);
	return (0);
}
