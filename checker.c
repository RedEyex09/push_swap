/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:22:00 by hel-magh          #+#    #+#             */
/*   Updated: 2024/02/24 14:37:51 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list **a)
{
	t_list	*stack_a;

	if (!(*a))
		return (0);
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

void	content(t_arg_chek *num, t_list **head)
{
	long long	k;

	k = 0;
	while (num->n[num->j])
	{
		num->l = 0;
		ft_str_pn(num->n[num->j]);
		while (num->n[num->j][num->l])
		{
			if (ft_pn(num->n[num->j][num->l + 1]))
				ft_exit();
			else if (ft_isdigit(num->n[num->j][num->l])
				|| ft_pn(num->n[num->j][num->l]))
				num->l++;
			else
				ft_exit();
		}
		k = ft_atoi(num->n[num->j]);
		if (duplicate(k, *head))
			ft_exit();
		add_num(head, k);
		num->j++;
	}
}

void	parsing(char **av, t_list **a)
{
	t_arg_chek	num;

	empty(&num, av);
	num.i = 1;
	while (av[num.i])
	{
		num.j = 0;
		num.n = ft_split(av[num.i], ' ');
		if (!num.n)
			ft_exit();
		content(&num, a);
		num.i++;
		ft_free_double(num.n);
	}
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac >= 2)
	{
		parsing(av, &a);
		ft_reader(&a, &b);
		if (is_sorted(&a) && !b)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		ft_lstclear(&a);
		// ft_lstclear(&b);
	}
}
