/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoham <marmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:34:51 by marmoham          #+#    #+#             */
/*   Updated: 2023/08/04 11:08:24 by marmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)

{
	int		len;
	char	*dest;

	len = ft_strlen(s1);
	dest = (char *)malloc(sizeof(char) * (len +1));
	if (dest == NULL)
		return (0);
	len = 0;
	while (s1[len] != '\0')
	{
		dest[len] = s1[len];
		len++;
	}
	dest[len] = '\0';
	return (dest);
}
/*int main()
{
    char str[] = "hello";
    printf("%s", ft_strdup(str));
}*/
