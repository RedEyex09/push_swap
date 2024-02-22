/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:38:46 by hel-magh          #+#    #+#             */
/*   Updated: 2024/02/22 19:31:23 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sortingt_list(t_list**a, t_list **b)
{
    t_list *stack_a;
    t_list *stack_b;
    int     tmp_index;
    
    stack_a = *a;
    stack_b = *b;
    tmp_index = low_cost_index(b);
    while (stack_b && stack_b->content != tmp_index && stack_b->next)
        stack_b = stack_b->next;
    while(stack_a)
    {
        if(stack_b->target == stack_a->content)
        {
            while ((*a)->content != stack_b->target && (*b)->content != stack_b->content)
           {
                if (stack_a->median == 0 && stack_b->median == 0)
                    rrr(a, b);
                else if (stack_a->median == 1 && stack_b->median == 1)
                    rr(a, b);
                else
                    break ;
           } 
            while ((*a)->content != stack_b->target)
           {
                if (stack_a->median == 0)
                    rra(a, 1);
                else if (stack_a->median == 1)
                    ra(a, 1);
                else
                    break ; 
           }
           
        break;
        }
        stack_a = stack_a->next;
    }
    stack_b = *b;
    while (stack_b)
    {
         if(tmp_index == stack_b->content)
          {      
             while((*b)->content != tmp_index)
           {
                if (stack_b->median == 0)
                    rrb(b, 1);
                else if (stack_b->median == 1)
                    rb(b, 1);
                else
                    break ;
           }
           break ;
          } 

        stack_b = stack_b->next;
    }  
}



void finisher(t_list **a, t_list **b)
{
     t_list *tmp;
     tmp = NULL;
    if(ft_lstsize(*a) != 3)
    {
        indexing(a, b);
        tmp = *a;
         while (tmp->content != min_max(a, 1))
         {
             tmp = tmp->next;
         }
        while (*a != tmp)
        {
           if(tmp->median == 1)
                ra(a, 1);
            else if(tmp->median == 0)
                rra(a, 1); 
        }
    }
}
void first_steps(t_list **a, t_list **b)
{
    int mid_av;
    index_value(*a);
    mid_av = min_max(a, 0) ;
    while(ft_lstsize(*a) > 3)
    {
        if ((*a)->index_value <= mid_av)
            pb(a,b);
        else
        {
            pb(a,b);
            rb(b, 1);
        }
    }
    if (ft_lstsize(*a) == 3)
    {
        sort_three(a);
        get_target(a, b);
get_cost(a, b);
    }
}
void stacks(t_list **a, t_list **b)
{
 
    if(is_sorted(a))
        exit(0);
    first_steps(a, b);
    while(ft_lstsize(*b) != 0)
    {
        get_target(a, b);
        get_cost(a, b);
        sortingt_list(a, b);
        pa(a, b);
    }
    finisher(a, b);
}







