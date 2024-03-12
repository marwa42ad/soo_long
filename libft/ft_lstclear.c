/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoham <marmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:04:00 by marmoham          #+#    #+#             */
/*   Updated: 2023/08/05 12:16:19 by marmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))

{
	if (!lst || !del || !(*lst))
		return ;
	ft_lstclear(&(*lst)->next, del);
	(del)((*lst)->content);
	free(*lst);
	*lst = NULL;
}
// void del_content(void *content)
// {
//     free(content);
// }
// int main()
// {
//     char *greet = malloc(3* sizeof(char));
//     char *student = malloc(6 * sizeof(char));
//     greet[0] = 'h';    
//     greet[1] = 'i';
//     student[0] = 'm';
//     student[1] = 'a';
//     student[2] = 'r';
//     student[3] = 'w';
//     student [4] = 'a';
//     t_list *node1 = ft_lstnew(greet);
//     ft_lstadd_back(&node1, ft_lstnew(student));
//     ft_lstclear(&node1, del_content);
//     return (0);
// }