/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoham <marmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:24:13 by marmoham          #+#    #+#             */
/*   Updated: 2023/08/05 12:09:48 by marmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)

{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n--)
	{
		*str++ = '\0';
	}
}
// int main()
// {
//     char str[12] = "hello world";
//     size_t len = 5;
//     printf("before bzero: %s\n", str);
//     ft_bzero(str, len);
//     printf("after bzero: %s\n", str);
//     return (0);
// }
