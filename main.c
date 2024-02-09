/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 10:09:04 by hel-magh          #+#    #+#             */
/*   Updated: 2024/02/09 21:31:11 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void content(t_arg_chek *num, t_list **head)
{
	long long k = 0;
	while (num->n[num->j])
	{
		num->l =0;
		ft_str_pn(num->n[num->j]);
		while(num->n[num->j][num->l])
		{
			if(ft_pn(num->n[num->j][num->l + 1]))
			{
				ft_printf("P or N double at last\n");
				ft_exit();
			}
			else if(ft_isdigit(num->n[num->j][num->l])
				|| ft_pn(num->n[num->j][num->l]))
				num->l++;
			else
			{
				ft_printf("content problem %c \n",num->n[num->j][num->l]);
				ft_exit();
			}
		}
		k = ft_atoi(num->n[num->j]);
		if(duplicate(k, *head) || (num->l == 11 && k != INT_MIN)
		|| k > INT_MAX || k < INT_MIN)
		{
		ft_printf("k = %d\n", k);
			ft_printf("Duplicate number or above max number\n");
            ft_exit();
		}
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
	while(av[num.i])
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
// void f(void)
// {
// 	system("leaks push_swap");
// }
int main(int ac, char **av)
{
	// atexit(f);
	if (ac >= 2)
	{
		parsing(av);
	}
}
