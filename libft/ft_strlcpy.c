/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoham <marmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 10:54:34 by marmoham          #+#    #+#             */
/*   Updated: 2023/08/05 12:30:35 by marmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)

{
	size_t	st;
	size_t	i;

	st = ft_strlen(src);
	if (dstsize == 0)
		return (st);
	i = 0;
	if (st == 0)
		dst[i] = src[i];
	while ((src[i] != '\0') && (i < (dstsize - 1)))
	{
		dst[i] = src[i];
		i++;
	}
	if (st < dstsize)
		dst[i] = src[i];
	else
		dst[i] = '\0';
	return (st);
}
// int main ()
// {
//     char dest[] = "hi";
//     char src[] = "marwa";
//     printf("%zu\n", ft_strlcpy(dest, src, 6));
// 	printf("%s\n", dest);
//     printf("%zu\n", ft_strlcpy(dest, src, 0));
// }
