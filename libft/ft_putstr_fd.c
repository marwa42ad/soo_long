/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoham <marmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:05:56 by marmoham          #+#    #+#             */
/*   Updated: 2023/08/05 12:25:51 by marmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)

{
	size_t	i;

	if ((s == NULL) || s[0] == 0)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
// #include <fcntl.h>
// int main()
// {
//     char s[] = "good morning";
//     int fd = open("anas", O_RDWR | O_CREAT, 0644);
//     ft_putstr_fd(s, fd);
// }
