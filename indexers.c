/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:55:31 by hel-magh          #+#    #+#             */
/*   Updated: 2024/02/23 20:44:14 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_value(t_list *stacka)
{
	t_list	*current_node;
	t_list	*compare_node;
	int		index;

	current_node = stacka;
	while (current_node != NULL)
	{
		compare_node = stacka;
		index = 0;
		while (compare_node != NULL)
		{
			if (current_node->content > compare_node->content)
				index++;
			compare_node = compare_node->next;
		}
		current_node->index_value = index;
		current_node = current_node->next;
	}
	
}

int	is_sorted(t_list **a)
{
	t_list	*stack_a;

	stack_a = *a;
	while (stack_a && stack_a->next)
	{
		if (stack_a->content <= stack_a->next->content)
			stack_a = stack_a->next;
		else
			return (0);
	}
	return (1);
}

int	low_cost_index(t_list **b)
{
	t_list	*stack_b;
	int		tmp;
	int		cost;

	tmp = 0;
	cost = 0;
	stack_b = *b;
	cost = stack_b->cost;
	tmp = stack_b->content;
	while (stack_b)
	{
		if (stack_b->cost < cost)
		{
			tmp = stack_b->content;
			cost = stack_b->cost;
		}
		stack_b = stack_b->next;
	}
	return (tmp);
}

void	indexer(t_list **m)
{
	t_list	*lst;
	int		median;
	int		i;

	i = 0;
	median = 0;
	lst = NULL;
	lst = *m;
	median = ft_lstsize(*m) / 2;
	while (lst)
	{
		lst->index = i;
		if (i <= median)
			lst->median = 1;
		else
			lst->median = 0;
		lst = lst->next;
		i++;
	}
}

void	indexing(t_list **a, t_list **b)
{
	indexer(a);
	indexer(b);
}
