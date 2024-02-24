/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:28:41 by hel-magh          #+#    #+#             */
/*   Updated: 2024/02/24 15:44:38 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **lst)
{
	if ((*lst)->content < (*lst)->next->content
		&& (*lst)->content < (*lst)->next->next->content
		&& (*lst)->next->content > (*lst)->next->next->content)
		rra(lst, 1);
	if ((*lst)->content > (*lst)->next->content
		&& (*lst)->content < (*lst)->next->next->content)
		sa(lst, 1);
	if ((*lst)->content > (*lst)->next->content
		&& (*lst)->next->content > (*lst)->next->next->content)
		sa(lst, 1);
	if ((*lst)->content < (*lst)->next->content
		&& (*lst)->next->next->content < (*lst)->content)
		rra(lst, 1);
	if ((*lst)->content > (*lst)->next->content
		&& (*lst)->next->content < (*lst)->next->next->content)
		ra(lst, 1);
}

void	sort_b(t_list **b, t_list *stack_b, int tmp_index)
{
	while (stack_b)
	{
		if (tmp_index == stack_b->content)
		{
			while ((*b)->content != tmp_index)
			{
				if (stack_b->median == 0)
					rrb(b, 1);
				else if (stack_b->median == 1)
					rb(b, 1);
				else
					break ;
			}
			break ;
		}
		stack_b = stack_b->next;
	}
}

void	sort_a2(t_list **a, t_list *stack_a, int target)
{
	while ((*a)->content != target)
	{
		if (stack_a->median == 0)
			rra(a, 1);
		else if (stack_a->median == 1)
			ra(a, 1);
		else
			break ;
	}
}

void	sort_a(t_list **a, t_list **b, t_list *stack_b)
{
	t_list	*stack_a;

	stack_a = *a;
	while (stack_a)
	{
		if (stack_b->target == stack_a->content && stack_a != *a)
		{
			while ((*a)->content != stack_b->target
				&& (*b)->content != stack_b->content)
			{
				if (stack_a->median == 0 && stack_b->median == 0)
					rrr(a, b, 1);
				else if (stack_a->median == 1 && stack_b->median == 1)
					rr(a, b, 1);
				else
					break ;
			}
			sort_a2(a, stack_a, stack_b->target);
			break ;
		}
		stack_a = stack_a->next;
	}
}
