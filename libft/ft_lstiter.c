/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoham <marmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:24:47 by marmoham          #+#    #+#             */
/*   Updated: 2023/08/04 13:05:27 by marmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))

{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*void print_content(void *content)
{
    printf("The content is : %s\n", (char *)content);
}
int main()
{
    t_list *lst = ft_lstnew("hello");
    ft_lstadd_back(&lst, ft_lstnew("marwa"));
    ft_lstiter(lst, print_content);
}*/