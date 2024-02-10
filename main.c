/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 10:09:04 by hel-magh          #+#    #+#             */
/*   Updated: 2024/02/10 09:28:22 by hel-magh         ###   ########.fr       */
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
		if (duplicate(k, *head) || max_check(num->l, k))
			ft_exit();
		add_num(head, k);
		ft_printf("%d\n", k);
		num->j++;
	}
}

void	parsing(char **av)
{
	t_arg_chek	num;
	t_list		*head;

	head = NULL;
	empty(&num, av);
	num.i = 1;
	while (av[num.i])
	{
		num.j = 0;
		num.n = ft_split(av[num.i], ' ');
		if (!num.n)
		{
			ft_printf("problem in split\n");
			ft_exit();
		}
		content(&num, &head);
		num.i++;
		ft_free_double(num.n);
	}
	ft_lstclear(&head);
}

int	main(int ac, char **av)
{
	if (ac >= 2)
	{
		parsing(av);
	}
}
