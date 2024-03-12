/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoham <marmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:16:44 by marmoham          #+#    #+#             */
/*   Updated: 2023/08/05 12:24:21 by marmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)

{
	size_t			i;
	unsigned char	*s;

	s = (unsigned char *)str;
	i = 0;
	while (n > i)
	{
		s[i] = c;
		i++;
	}
	return (str);
}
// int main()
// {
//     char str[] = "hello everybody";
//     printf("at the begining : %s", str);
//     ft_memset(str, 'm', 4);
//     printf("\n after memset: %s", str);
// }
