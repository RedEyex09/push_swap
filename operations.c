/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:38:46 by hel-magh          #+#    #+#             */
/*   Updated: 2024/02/24 11:44:17 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sortingt_list(t_list**a, t_list **b)
{
	t_list	*stack_b;
	int		tmp_index;

	stack_b = *b;
	tmp_index = low_cost_index(b);
	while (stack_b && stack_b->content != tmp_index && stack_b->next)
		stack_b = stack_b->next;
	sort_a(a, b, stack_b);
	stack_b = *b;
	sort_b(b, stack_b, tmp_index);
}

void	finisher(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = NULL;
	if (ft_lstsize(*a) != 3)
	{
		indexing(a, b);
		tmp = *a;
		while (tmp->content != min_max(a, 1))
		{
			tmp = tmp->next;
		}
		while (*a != tmp)
		{
			if (tmp->median == 1)
				ra(a, 1);
			else if (tmp->median == 0)
				rra(a, 1);
		}
	}
}

void	first_steps(t_list **a, t_list **b)
{
	int	mid_av;

	index_value(*a);
	mid_av = min_max(a, 0);
	while (ft_lstsize(*a) > 3)
	{
		if ((*a)->index_value <= mid_av)
			pb(a, b, 1);
		else
		{
			pb(a, b, 1);
			rb(b, 1);
		}
	}
	if (ft_lstsize(*a) == 3)
	{
		sort_three(a);
		get_target(a, b);
		get_cost(a, b);
	}
}

void	stacks(t_list **a, t_list **b)
{
	if (is_sorted(a))
		exit(0);
	first_steps(a, b);
	while (ft_lstsize(*b) != 0)
	{
		get_target(a, b);
		get_cost(a, b);
		sortingt_list(a, b);
		pa(a, b, 1);
	}
	finisher(a, b);
}
