/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:28:41 by hel-magh          #+#    #+#             */
/*   Updated: 2024/02/22 19:31:26 by hel-magh         ###   ########.fr       */
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
