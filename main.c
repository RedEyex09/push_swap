/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 10:09:04 by hel-magh          #+#    #+#             */
/*   Updated: 2024/02/19 08:55:07 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	// t_list		*a;
	// t_list		*b;
	
	// a = NULL;
	// b = NULL;
	// ft_memset(&b, 0, sizeof(b));
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
// void f(void)
// {
// 	system("leaks push_swap");
// }
int	main(int ac, char **av)
{
	t_list *a;
	t_list *b;
	
	a = NULL;
	b = NULL;
	// atexit(f);
	if (ac >= 2)
	{
		parsing(av, &a);
		if (ft_lstsize(a) == 3)
		{
			 sort_three(&a);
		}
		else if (ft_lstsize(a) == 2 && !is_sorted(&a))
			ra(&a, 1);
		else
			stacks(&a, &b);
		ft_lstclear(&a);
		ft_lstclear(&b);
	}
}



