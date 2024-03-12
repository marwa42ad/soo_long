/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoham <marmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:39:32 by marmoham          #+#    #+#             */
/*   Updated: 2023/08/03 12:21:57 by marmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))

{
	if (!lst || !del)
		return ;
	(del)(lst->content);
	free(lst);
	lst = NULL;
}
/*void del_content(void *content)
{
    free(content);
}
int main()
{
    char *greet = malloc(5 * sizeof(char));
    greet[0] = 'h';    
    greet[1] = 'i';
    t_list *node1 = ft_lstnew(greet);
    ft_lstdelone(node1, del_content);
    printf("%s", node1->content);
    return (0);
}*/
