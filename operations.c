/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:38:46 by hel-magh          #+#    #+#             */
/*   Updated: 2024/02/14 11:44:15 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void printer(t_list **t, int s)
{
    t_list *lst;
    
    lst = NULL;
    lst = *t;
    if (s == 'a')
    {
        while (lst)
        {
            ft_printf("stack a -> %d\n", lst->content);
            lst = lst->next;
        }
    }
    if (s == 'b')
    {
        while (lst)
        {
            ft_printf("stack b -> %d\n", lst->content);
            lst = lst->next;
        }
    }
    ft_printf("/-----------------------/\n");
}

void stacks(t_list **a, t_list **b)
{
    printer(a, 'a');
    // ra(a, 1);
    // printer(a, 'a');
    
    // pa(a, b);
     pb(a, b);
     printer(a, 'a');
     printer(b, 'b');
     pb(a, b);
     printer(b, 'b');
     rr(a, b);
     printer(a, 'a');
     printer(b, 'b');
    // rr(a, b);
    // printer(a, 'a');
    // printer(b, 'b');
    // pa(a, b);
    // pa(a, b);
    // pa(a, b);
    // pa(a, b);
    // printer(a, 'a');
    // printer(b, 'b');
    // rrr(a, b);

    // // rr(a, b);
    // printer(a, 'a');
    // printer(b, 'b');
    
    
}
