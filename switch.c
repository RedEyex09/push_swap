/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:07:18 by hel-magh          #+#    #+#             */
/*   Updated: 2024/02/13 15:08:19 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_switch(t_list **stack)
{
    t_list *temp1;
    t_list *temp2;
    
    if (*stack == NULL || (*stack)->next == NULL)
        return;

    temp1 = *stack;
    temp2 = temp1->next;

    temp1->next = temp2->next;
    temp1->prev = temp2;
    temp2->next = temp1;
    temp2->prev = NULL;

    if (temp1->next)
        temp1->next->prev = temp1;

    *stack = temp2;
}

void sa(t_list **a, int i)
{
    ft_switch(a);
    if (i == 1 )
        ft_printf("sa\n");
}
void sb(t_list **b, int i)
{
    ft_switch(b);
    if (i == 1 )
     ft_printf("sb\n");
}
void ss(t_list **a, t_list **b)
{
    sa(a, 0);
    sb(b, 0);
    ft_printf("ss\n");
}