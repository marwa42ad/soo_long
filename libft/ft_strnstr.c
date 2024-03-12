/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoham <marmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:13:46 by marmoham          #+#    #+#             */
/*   Updated: 2023/08/05 12:32:04 by marmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)

{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while ((i < len) && haystack[i] != '\0')
	{
		j = 0;
		while (needle[j] && haystack[i + j] == needle[j] && ((i + j) < len))
		{
			if (needle[j + 1] == '\0')
			{
				return ((char *)&haystack[i]);
			}
			j++;
		}
		i++;
	}
	return (0);
}
// int main()
// {
//     char big[] = "marwa mostafa";
//     char little[] = "wa";
//     printf("%s\n",ft_strnstr(big, little, 3));
//     printf("%s\n",ft_strnstr(big, little, 5));
// }
