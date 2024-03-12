/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoham <marmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:21:48 by marmoham          #+#    #+#             */
/*   Updated: 2023/08/02 16:57:02 by marmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)

{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*int main()
{
   t_list *blue = ft_lstnew("marwa");
   t_list *green = ft_lstnew("Mostafa");
   
   
   t_list *mylist = NULL;
   ft_lstadd_front(&mylist, green);
   ft_lstadd_front(&mylist, blue);
   t_list *current = mylist;
   
   while (current != NULL)
   {
    printf("%s\n", (char *)current->content);
    current = current->next;
   }
   return (0);
}*/
