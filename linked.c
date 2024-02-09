/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:45:10 by hel-magh          #+#    #+#             */
/*   Updated: 2024/02/09 19:25:24 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	temp = ft_lstlast(*lst);
	temp->next = new;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new -> next = *lst;
	*lst = new;
}


t_list  *ft_lstnew(int content)
{
        t_list  *elem;

        elem = malloc(sizeof(t_list));
        if (!elem)
        {
           ft_printf("Memory allocation error\n");
           ft_exit();
        }
        elem -> content = content;
        elem -> next = NULL;
        return (elem);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp -> next)
		tmp = tmp -> next;
	return (tmp);
}
void	ft_lstdelone(t_list *lst)
{
	if (!lst)
		return ;
	free(lst);
	// lst = NULL;
}

void    ft_lstclear(t_list **lst)
{
        t_list  *tmp;

        if (lst == NULL)
                return ;
        while (*lst)
        {
                tmp = (*lst)->next;
                ft_lstdelone(*lst);
                *lst = tmp;
        }
        // free(*lst);
         *lst = NULL;
}
int     ft_lstsize(t_list *lst)
{
        int     size;

        size = 0;
        if (lst == NULL)
                return (0);
        while (lst)
        {
                lst = lst->next;
                size++;
        }
        return (size);
}
