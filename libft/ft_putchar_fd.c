/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoham <marmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:25:57 by marmoham          #+#    #+#             */
/*   Updated: 2023/08/03 13:05:05 by marmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)

{
	write(fd, &c, 1);
}
/*#include <fcntl.h>
int main()
{
    int fd = open("marwa", O_RDWR | O_CREAT, 0644);
    char w = 'c';
    ft_putchar_fd(w, fd);
    //printf("chracter written to file.\n");
    return (0);
}*/
