/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoham <marmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:08:58 by marmoham          #+#    #+#             */
/*   Updated: 2023/08/05 12:08:51 by marmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	num;

	sign = 1;
	num = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign = -1;
	}
	if (*str == '+' || *str == '-')
	{
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + *str - '0';
		str++;
	}
	num = sign * num;
	return (num);
}
/*int main()
{
    char *str = "      +-1234asd56";
    int numb = ft_atoi(str);
    printf("%d", numb);
    return (0);
}*/

// #include <stdio.h>
// int main(int argc, char **argv)
// {
// 	(void)argc;
// 	printf("%i\n", ft_atoi(argv[1]));
// 	printf("%i\n", atoi(argv[1]));
// }