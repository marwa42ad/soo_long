/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoham <marmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 10:38:50 by marmoham          #+#    #+#             */
/*   Updated: 2023/08/05 12:33:39 by marmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	char_check(char const *str, char const c)

{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (*(str + i))
	{
		if (*(str + i) == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*str_memory(size_t n)

{
	char	*str;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)

{
	char	*strimed;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (*(s1 + start) && char_check(set, *(s1 + start)))
		start++;
	end = ft_strlen(s1);
	while (end > start && char_check(set, *(s1 + (end - 1))))
		end--;
	strimed = str_memory(end - start);
	if (!strimed)
		return (NULL);
	i = 0;
	while ((start + i) < end)
	{
		*(strimed + i) = *(s1 + (start + i));
		i++;
	}
	*(strimed + i) = '\0';
	return (strimed);
}
// int main()
// {
//     char str[] = "\t\twelcome to 42 \t\t";
//     char set[] = "\t";
//     char* trimmed = ft_strtrim(str, set);
//     printf("result 1: %s\n", trimmed);
//     printf("result 2: %s\n", ft_strtrim("   hello, everyone  ", " "));
//     printf("result 3: %s\n", ft_strtrim("nothing trimmed", " "));
// }
