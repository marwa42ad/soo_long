/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoham <marmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:01:55 by marmoham          #+#    #+#             */
/*   Updated: 2023/08/05 12:23:52 by marmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//memmove can handle the overlapping
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)

{
	unsigned char		*dt;
	const unsigned char	*sr;
	size_t				i;

	i = 0;
	dt = (unsigned char *)dst;
	sr = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (sr < dt)
	{
		while (len--)
		{
			dt[len] = sr[len];
		}
	}
	else
	{
		while (len--)
		{
			dt[i] = sr[i];
			i++;
		}
	}
	return (dst);
}
// int main()
//  {
//      char dest[10];
//      const char src[] = "marwa";
//      printf("after memmove dest : %s\n", ft_memmove(dest, src, 6));
// }
