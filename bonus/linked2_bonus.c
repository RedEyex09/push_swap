/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 09:22:32 by hel-magh          #+#    #+#             */
/*   Updated: 2024/02/25 09:18:00 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	if (lst == NULL)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst);
		*lst = tmp;
	}
	free(*lst);
	*lst = NULL;
}

int	ft_lstsize(t_list *lst)
{
	int	size;

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
