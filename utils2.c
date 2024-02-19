/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:13:58 by hel-magh          #+#    #+#             */
/*   Updated: 2024/02/19 08:53:35 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_check(int i, long long k)
{
	return ((i == 11 && k != INT_MIN) || k > INT_MAX || k < INT_MIN);
}

void	add_num(t_list **head, int n)
{
	t_list	*new_node;

	new_node = ft_lstnew(n);
	ft_lstadd_back(head, new_node);
}

int	duplicate(int n, t_list *head)
{
	while (head)
	{
		if (head->content == n)
			return (1);
		head = head ->next;
	}
	return (0);
}

void	empty(t_arg_chek *num, char **av)
{
	num->i = 1;
	while (av[num->i])
	{
		num->j = 0;
		while (av[num->i][num->j] != '\0')
		{
			if (av[num->i][num->j] != ' ')
				break ;
			num->j++;
		}
		if (av[num->i][num->j] == '\0')
			ft_exit();
		num->i++;
	}
}
