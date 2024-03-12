/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoham <marmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:18:13 by marmoham          #+#    #+#             */
/*   Updated: 2023/08/05 12:41:36 by marmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)

{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}
// int main()
// {
//    t_list *node1 = ft_lstnew("marwa");
//    t_list *node2 = ft_lstnew("Mostafa");
//    t_list *mylist = NULL;
//    ft_lstadd_back(&mylist, node1);
//    ft_lstadd_back(&mylist, node2);
//    t_list *current = mylist;
//    while (current != NULL)
//    {
//     printf("%s\n", (char *)current->content);
//     current = current->next;
//    }
//    return (0);
// }