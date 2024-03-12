/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoham <marmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:46:23 by marmoham          #+#    #+#             */
/*   Updated: 2023/08/05 12:31:22 by marmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)

{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (((unsigned char)s1[i] != '\0'
			&& (unsigned char)s1[i] == (unsigned char)s2[i]) && (i < n - 1))
	{
		i++;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
// int main()
// {
//     printf("%d\n", ft_strncmp("marwa", "marwa", 4));
//     printf("%d\n", ft_strncmp("marwa", "maRwa", 3));
//     printf("%d\n", ft_strncmp("maRwa", "marwa", 3));
//     printf("%d\n", ft_strncmp("marwa", "marwa", 0));
// }
