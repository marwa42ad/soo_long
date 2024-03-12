/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoham <marmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:04:57 by marmoham          #+#    #+#             */
/*   Updated: 2023/10/12 13:20:13 by marmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)

{
	char	*memory;
	size_t	i;

	i = 0;
	if (size != 0 && count > UINT32_MAX / size)
		return (NULL);
	memory = malloc(count * size);
	if (memory == NULL)
		return (0);
	while (i < (count * size))
	{
		memory[i] = 0;
		i++;
	}
	return (memory);
}
// int main()
// {
//     int i = 0;
//     int n = 4;
//  int *s = calloc(n, sizeof(int));// allocate and zero out an arry of 4int
// if (s)
// {
//     while (i < n)
//     {
//         printf("s[%d] == %d\n", i, s[i]);
//         i++;
//     }
// }
// }
