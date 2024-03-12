/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoham <marmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:36:25 by marmoham          #+#    #+#             */
/*   Updated: 2023/08/05 12:32:41 by marmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)

{
	int				len;
	unsigned char	*s;

	len = ft_strlen(str);
	s = (unsigned char *)str;
	if (str == 0)
		return (0);
	if (c == '\0')
	{
		return ((char *)&s[len]);
	}
	while (len >= 0)
	{
		if (s[len] == (char)c)
			return ((char *)&s[len]);
		len--;
	}
	return (NULL);
}
// #include <stdio.h>
// int main()
// {
//     char str[] = "good morning";
//     char c = 'o';
//     printf("%s\n", ft_strrchr(str, c));
//     return (0);
// }
