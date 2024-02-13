/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:38:46 by hel-magh          #+#    #+#             */
/*   Updated: 2024/02/13 12:25:44 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void stacks(t_list **a, t_list **b)
{
    t_list *lst;
    t_list *lst2;
    

    pa(a, b);
    lst = NULL;
    lst = *a;
    while (lst)
    {
        ft_printf("stack a : %d\n", lst->content);
        lst = lst->next;
    }

    lst2 = NULL;
    lst2 = *b;
    while (lst2)
    {
        
        ft_printf("stack b : %d\n", lst2->content);
        lst2 = lst2->next;
    }
    pa(a, b);
     lst = NULL;
    lst = *a;
    while (lst)
    {
        ft_printf("stack a : %d\n", lst->content);
        lst = lst->next;
    }

    lst2 = NULL;
    lst2 = *b;
    while (lst2)
    {
        
        ft_printf("stack b : %d\n", lst2->content);
        lst2 = lst2->next;
    }
    pb(a, b); 
     lst = NULL;
    lst = *a;
    while (lst)
    {
        ft_printf("stack a : %d\n", lst->content);
        lst = lst->next;
    }

    lst2 = NULL;
    lst2 = *b;
    while (lst2)
    {
        
        ft_printf("stack b : %d\n", lst2->content);
        lst2 = lst2->next;
    }// Pass the address of b
}