/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:42:54 by hel-magh          #+#    #+#             */
/*   Updated: 2024/02/13 15:43:25 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate(t_list **stack)
{
    t_list *temp1;
    t_list *temp2;
    
    if (*stack == NULL || (*stack)->next == NULL)
        return;
    temp1 = *stack;
    temp2 = ft_lstlast(*stack);
    (*stack) = (*stack)->next;
    ft_lstadd_back(&temp2, temp1);
    
}

void ra(t_list **a, int i)
{
    rotate(a);
    if (i == 1)
        ft_printf("ra\n");
}
void rb(t_list **b, int i)
{
    rotate(b);
    if (i == 1)
        ft_printf("ra\n");
}
void rr(t_list **a, t_list **b)
{
    ra(a, 0);
    rb(b, 0);
    ft_printf("rr\n");
}