/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoham <marmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:41:28 by marmoham          #+#    #+#             */
/*   Updated: 2023/08/04 11:56:37 by marmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*str_memory(size_t n)

{
	char	*str;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))

{
	size_t	i;
	char	*str;
	char	*result;

	if (!s)
		return (NULL);
	str = str_memory(ft_strlen(s));
	if (!str)
		return (NULL);
	i = 0;
	result = str;
	while (*s)
		*str++ = f(i++, *s++);
	*str = '\0';
	return (result);
}
/*char uppercase(unsigned int i, char c)
{
    if (i % 2 == 0)
    {
        c = c - 32;
    }
    //else
    //{
        //c = c + 32;
    //}
    return (c);
}
int main()
{
    char s[]= "marwa";
    char *str = ft_strmapi(s, &uppercase);
    printf("the string : %s\n", str);
    return (0);
}*/