/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoham <marmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:55:34 by marmoham          #+#    #+#             */
/*   Updated: 2023/08/03 12:36:54 by marmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)

{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
/*int main()
{
    t_list *node1 = ft_lstnew("marwa");
    t_list *node2 = ft_lstnew("Mostafa");
    
    node1->next = node2;
    node2->next = NULL;
    
    int size = ft_lstsize(node1);
    printf("The number of nude is :%d\n", size);
}*/
