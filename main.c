/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 10:09:04 by hel-magh          #+#    #+#             */
/*   Updated: 2024/02/08 16:11:11 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int duplicate(int n, t_list *head)
{
	while (head)
	{
		if(head->content == n)
		{
			return (1);
		}
		head = head ->next;
	}
	return (0);
}
void add_num(t_list **head, int n)
{
	t_list *new_node;

	// new_node = NULL;
	
	new_node = ft_lstnew(n);
	ft_lstadd_front(head, new_node);
}
void content(t_arg_chek *num, t_list **head)
{
	int k = 0;
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
		if(duplicate(k, *head))
		{
			ft_printf("Duplicate number: %d\n", k);
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
	num.i = 1;
	while(av[num.i])
	{
		num.j = 0;
		while(av[num.i][num.j] != '\0')
		{
			if (av[num.i][num.j] != ' ')
				break ;
			num.j++;
		}
		if(av[num.i][num.j] == '\0')
		{
			ft_printf("Empty String\n");
			ft_exit();
		}
		num.i++;
	}
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
	}
		ft_free_double(num.n);
		ft_lstclear(&head);	
	
}

int main(int ac, char **av)
{
	if (ac >= 2)
	{
		parsing(av);
	}
}
