/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoham <marmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 10:18:34 by marmoham          #+#    #+#             */
/*   Updated: 2023/08/05 11:04:24 by marmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;

	new = NULL;
	if (!lst)
		return (NULL);
	while (lst != NULL)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			del(tmp->content);
			free(tmp);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&new, tmp);
	}
	return (new);
}
/*void *transform_content(void *content)
{
    // Check if the content pointer is valid
    if (content == NULL) {
        return NULL;
}
    char *str = (char *)content;
    char *result = strdup(str); // Duplicate the original content
    // Convert each character in the duplicated string to uppercase
    for (size_t i = 0; result[i]; i++) {
        result[i] = ft_toupper(result[i]);
    }
    return result;
}

void free_content(void *content)
{
    free(content);
}
int main()
{
    t_list *lst = ft_lstnew("hi");
    ft_lstadd_back(&lst, ft_lstnew("marwa"));
    t_list *new_lst = ft_lstmap(lst, transform_content, free_content);
    t_list *current = new_lst;
    while (current != NULL)
    {
        printf("%s\n", (char *)current->content);
        current = current->next;
    }
    return (0); 
}*/