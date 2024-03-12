/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoham <marmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:33:12 by marmoham          #+#    #+#             */
/*   Updated: 2023/08/05 12:23:48 by marmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)

{
	unsigned char	*sr;
	unsigned char	*dst;
	size_t			i;

	sr = (unsigned char *)src;
	dst = (unsigned char *)dest;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		dst[i] = sr[i];
		i++;
	}
	return (dst);
}
// int main()
// {
//     const char src[13] = "hello";
//     char dest[10] = "hi";
//     printf("befor memcpy dest : %s\n", dest);
//     printf("after memcpy dest : %s\n", ft_memcpy(dest, src,4));
// 	printf("after memcpy dest : %s\n", memcpy(dest, src,4));
//     return (0);
// }
