/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coster.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:05:29 by hel-magh          #+#    #+#             */
/*   Updated: 2024/02/22 19:27:28 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost(t_list **a, int target)
{
	t_list	*stack_a;

	stack_a = *a;
	while (stack_a)
	{
		if (stack_a->content == target)
			return (stack_a->cost);
		stack_a = stack_a->next;
	}
	return (0);
}

void	get_cost(t_list **a, t_list **b)
{
	t_list	*stack_a;
	t_list	*stack_b;

	indexing(a, b);
	stack_a = *a;
	while (stack_a)
	{
		if (stack_a->median == 1)
			stack_a->cost = stack_a->index;
		else
			stack_a->cost = ft_lstsize(*a) - stack_a->index;
		stack_a = stack_a->next;
	}
	stack_b = *b;
	while (stack_b)
	{
		if (stack_b->median == 1)
			stack_b->cost = stack_b->index + cost(a, stack_b->target);
		else
			stack_b->cost = ft_lstsize(*b) - stack_b->index
				+ cost(a, stack_b->target);
		stack_b = stack_b->next;
	}
}

void	get_targeter(t_list **a, t_list *b, int max, int min)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = *a;
	stack_b = b;
	while (stack_a)
	{
		if (stack_b->content > max)
		{
			stack_b->target = min;
			break ;
		}
		else if (stack_a->content > stack_b->content
			&& stack_a->content < stack_b->target)
			stack_b->target = stack_a->content;
		stack_a = stack_a->next;
	}
}

void	get_target(t_list **a, t_list **b)
{
	t_list	*stack_b;
	int		min;
	int		max;

	stack_b = *b;
	min = min_max(a, 1);
	max = min_max(a, 2);
	while (stack_b)
	{
		stack_b->target = max;
		get_targeter(a, stack_b, max, min);
		stack_b = stack_b->next;
	}
}

int	min_max(t_list **a, int i)
{
	t_list		*mm;
	t_arg_chek	v;

	ft_memset(&v, 0, sizeof(v));
	mm = *a;
	while (mm)
	{
		if (!v.min || v.min > mm->content)
			v.min = mm->content;
		if (!v.max || v.max < mm->content)
			v.max = mm->content;
		mm = mm->next;
		v.j++;
	}
	if (i == 1)
		return (v.min);
	if (i == 2)
		return (v.max);
	return (v.j / 2);
}
