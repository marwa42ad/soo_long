/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoham <marmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:40:40 by marmoham          #+#    #+#             */
/*   Updated: 2023/08/03 11:56:25 by marmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)

{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
// int main()
// {
//     int cat = '\n';//this not printable new line
//     printf("%d", ft_isprint(cat));
// }
