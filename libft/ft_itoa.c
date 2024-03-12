/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoham <marmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 15:04:07 by marmoham          #+#    #+#             */
/*   Updated: 2023/08/05 12:12:38 by marmoham         ###   ########.fr       */
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

static int	ft_nb_len(int number)

{
	int	len;

	len = 0;
	if (number < 1)
		len++;
	while (number)
	{
		number /= 10;
		len++;
	}
	return (len);
}

static long long	ft_abs_val(long long n)

{
	long long	nb;

	nb = 1;
	if (n < 0)
		nb *= -n;
	else
		nb *= n;
	return (nb);
}

char	*ft_itoa(int n)
{
	int				len;
	int				sign;
	unsigned int	nbr;
	char			*str;

	sign = 0;
	if (n < 0)
		sign = 1;
	len = ft_nb_len(n);
	str = str_memory(len);
	if (!str)
		return (NULL);
	*(str + len) = '\0';
	nbr = ft_abs_val(n);
	while (len--)
	{
		*(str + len) = 48 + nbr % 10;
		nbr /= 10;
	}
	if (sign)
		*(str) = 45;
	return (str);
}
// int main()
// {
//     char *str = ft_itoa(-2147483648);
//     printf("the string number is : %s\n", str);
//     printf("the string number is : %s\n", ft_itoa(2147483647));
// }
