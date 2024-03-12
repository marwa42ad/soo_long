/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoham <marmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:18:13 by marmoham          #+#    #+#             */
/*   Updated: 2023/08/03 12:33:48 by marmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)

{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*int main()
{
    t_list *node1 = ft_lstnew("Hi");
    t_list *node2 = ft_lstnew("marwa");
    t_list *node3 = ft_lstnew("Mostafa");
    
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    
    t_list *lastnude = ft_lstlast(node1);
    printf("The last nude of list is :%s\n", (char *)lastnude->content);
}*/
