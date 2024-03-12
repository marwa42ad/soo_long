/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoham <marmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:07:25 by marmoham          #+#    #+#             */
/*   Updated: 2023/08/04 15:20:07 by marmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//locates the first occurrence of c
// in the string pointed to by s
//The terminating null character is
//considered to be part of the string;
//therefore if c is `\0', the functions
// locate the terminating `\0'
#include "libft.h"

char	*ft_strchr(const char *s, int c)

{
	while (*s != (unsigned char)c)
	{
		if (*s == '\0')
		{
			return (NULL);
		}
		s++;
	}
	return ((char *)s);
}
// int main()
// {
//     const char str[] = "goodmorning";
//     const char c = ' ';
//     printf("%s\n", ft_strchr(str, c));
//     printf("%s\n", ft_strchr(str, 't' + 256));
//     printf("%s\n", strchr(str, 't' + 256));
//     return (0);
// }
