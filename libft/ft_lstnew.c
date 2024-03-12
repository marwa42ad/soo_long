/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoham <marmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:23:38 by marmoham          #+#    #+#             */
/*   Updated: 2023/08/02 16:35:18 by marmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)

{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
// int main()
// {
//     char *s = (char *)malloc(sizeof(char) * 3);
//     s = NULL;
//     if (!s)
//         return (0);
//     s = "42";
//     t_list *new_node = ft_lstnew(s);
//     if (!new_node)
//         return(1);
//     printf("the string is : %s\n", s);
//     s = "43";
//     printf("second print is : %s\n", s);
//     return (0);
// }
// int main()
// {
//    t_list *node1 = ft_lstnew("Hello");
//    t_list *node2 = ft_lstnew("everyone");
//    node1->next = node2;
//    node2->next = NULL;
// //    t_list *head = (node1);
//    while (node1 != NULL)
//    {
//     // printf("%s\n",(char *)head->content);
//     node1 = node1->next;
//    }
// }
/*int main()
{
    char *content = "Hello";
    t_list *node = ft_lstnew(content);
    printf("%s", (char *)node->content);
}*/
