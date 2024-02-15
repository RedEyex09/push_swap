/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:28:12 by hel-magh          #+#    #+#             */
/*   Updated: 2024/02/14 12:19:14 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_list **stack)
{
	t_list	*temp1;
	t_list	*temp2;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp1 = *stack;
	temp2 = ft_lstlast(*stack);
	temp2->next = temp1;
	temp2->prev->next = NULL;
	temp2->prev = NULL;
	temp1->prev = temp2;
	*stack = temp2;
}

void	rra(t_list **a, int i)
{
	if (*a)
		reverse_rotate(a);
	if (i == 1)
		ft_printf("rra\n");
}

void	rrb(t_list **b, int i)
{
	if (*b)
		reverse_rotate(b);
	if (i == 1)
		ft_printf("rrb\n");
}

void	rrr(t_list **a, t_list **b)
{
	if (*a && *b)
	{
		rra(a, 0);
		rrb(b, 0);
		ft_printf("rrr\n");
	}
}
