/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:24:57 by hel-magh          #+#    #+#             */
/*   Updated: 2024/02/23 18:54:33 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **a, t_list **b)
{
	t_list	*new;

	new = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	new->next = NULL;
	new->prev = NULL;
	if (*b)
		(*b)->prev = new;
	ft_lstadd_front(b, new);
}

void	pa(t_list **a, t_list **b, int i)
{
	if (*b)
		push(b, a);
	if (i == 1)
		ft_printf("pa\n");
}

void	pb(t_list **a, t_list **b, int i)
{
	if (*a)
		push(a, b);
	if (i == 1)
		ft_printf("pb\n");
}
