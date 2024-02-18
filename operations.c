/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:38:46 by hel-magh          #+#    #+#             */
/*   Updated: 2024/02/18 12:43:44 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void printer(t_list **t, int s, int i)
{
    t_list *lst;
    if (i == 0)
    {
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
    else
    {lst = NULL;
    lst = *t;
    if (s == 'a')
    {
        while (lst)
        {
            ft_printf("stack a -> %d index ->  %d cost -> %d\n", lst->content, lst->index, lst->median, lst->cost);
            lst = lst->next;
        }
    }
    if (s == 'b')
    {
        while (lst)
        {
            ft_printf("stack b -> %d index -> %d median ->  %d Target -> %d cost -> %d\n", lst->content, lst->index, lst->median, lst->target, lst->cost);
            lst = lst->next;
        }
    }
    ft_printf("/-----------------------/\n");
    }
    
}
int min_max(t_list **a)
{
    t_list *mm;
    int     min;
    int     max;

    mm = *a;
    while(mm)
    {
        if(!min || min > mm->content)
            min = mm->content;
        if (!max || max < mm->content)
            max = mm->content;
        mm = mm->next;
    }
    return((min + max) / 2);
}
void sort_three(t_list **a)
{
    t_list *mm;
    t_list *tmp;
    
    mm = *a;
    
    while(mm && mm->next)
    {
        if(mm->content <= mm->next->content)
            mm = mm->next;
        else
        {
            tmp = mm->next;
            mm->next = tmp->next;
            if(tmp->next)
                tmp->next->prev = mm;
            tmp->prev = mm->prev;
            mm->prev = tmp;
            tmp->next = mm;
            if (tmp->prev)
                tmp->prev->next = tmp;
            else
                *a = tmp;
            mm = *a;
        }

    }
}
void indexing(t_list **a, t_list **b)
{
    t_list *lst;
    int median;
    
    int i = 0;
    median = 0;
    lst = NULL;
    lst = *a;
    median = ft_lstsize(*a) / 2;
    while (lst)
    {
        lst->index = i;
        if (i <= median)
            lst->median = 1;
        lst = lst->next;
        i++;
    }
    i = 0;
    median = 0;
    lst = NULL;
    lst = *b;
    median = ft_lstsize(*b) / 2;
    while (lst)
    {
        lst->index = i;
        if (i <= median)
            lst->median = 1;
        lst = lst->next;
        i++;
    }
    
    
}
int cost(t_list **a,int target)
{
     t_list *stack_a;

    stack_a = *a;
     while(stack_a)
     {
        if(stack_a->index == target)
            return(stack_a->cost);
        stack_a = stack_a->next;
     }
     return(0);
}
void get_cost(t_list **a, t_list **b)
{
    t_list *stack_a;
    t_list *stack_b;
    
    stack_a = *a;  
    while(stack_a)
    {
        if (stack_a->median == 1)
            stack_a->cost = stack_a->index;
        else
            stack_a->cost = ft_lstsize(*a) - stack_a->index;
        stack_a = stack_a->next;
    }
    stack_b = *b;  
    while(stack_b)
    {
        if (stack_b->median == 1)
            stack_b->cost = stack_b->index + cost(a, stack_b->target);
        else
            stack_b->cost = ft_lstsize(*b) - stack_b->index + cost(a, stack_b->target);
        stack_b = stack_b->next;
    }
}
void get_target(t_list **a, t_list **b)
{
    t_list *stack_a;
    t_list *stack_b;
    int     tmp;
    int diff;
    
    diff = 0;
    stack_b = *b;  
    while(stack_b)
    {
        tmp = INT_MAX;
        stack_a = *a;
        while(stack_a)
        {
            diff = stack_a->content - stack_b->content;
            if (stack_a->content > stack_b->content && diff < tmp)
            {
                tmp = diff;
                stack_b->target = stack_a->index;
            }
            stack_a = stack_a->next;
        }
        stack_b = stack_b->next;
    }
    get_cost(a, b);
}

int low_cost_index(t_list **b)
{
    t_list *stack_b;

    int tmp = 0;
    int cost = 1;
    stack_b = *b; 
    while(stack_b)
    {
        if (stack_b->cost <= cost && tmp >= stack_b->index)
        {
            tmp = stack_b->index;
            cost = stack_b->cost;
        }
        stack_b = stack_b->next; 
    }
    return(tmp);
}
void sortingt_list(t_list**a, t_list **b)
{
    t_list *stack_a;
    t_list *stack_b;
    int     tmp_index;
    int     i = 0;
    
    stack_a = *a;
    stack_b = *b;
    tmp_index = low_cost_index(b);
    while (stack_b && tmp_index > i )
    {
        stack_b = stack_b -> next;
        i++;
    }
    while(stack_a)
    {
        if(stack_b -> target == stack_a->index)
          {      
           if (stack_a->median == 0)
           {
                rra(a, 1);
           }
           else if (stack_a->median == 1)
           {
                ra(a, 1);
           }
                
           if(stack_a->prev == NULL)
            {
                ft_printf("GOOOD FOR A\n");
                break ;
            }
           
          } 
        ft_printf("show 1\n");
        stack_a = stack_a->next;
    }
    stack_b = *b;
    while (stack_b)
    {
         if(tmp_index == stack_b->index)
          {      
           if (stack_b->median == 0)
           {
                rrb(a, 1);
           }
           else if (stack_b->median == 1 && tmp_index != 0)
           {
                rb(a, 1);
           }
           if(stack_b->prev == NULL)
            {
                pa(a, b);
                ft_printf("GOOOD FOR B\n");
            }
           
          } 

        stack_b = stack_b->next;
    }
    
    
    // ft_printf("My value %d my target %d My index %d My cost %d\n", stack_b->content, stack_b->target, tmp_index, stack_b->cost );
    
}
int is_sorted(t_list **a)
{
    t_list *stack_a;

    stack_a = *a;

    while (stack_a)
    {
        if(stack_a->content <= stack_a->next->content)
            stack_a = stack_a->next;
        else
            return(1);
    }
    return(0);
    
}
void stacks(t_list **a, t_list **b)
{
    int mid_av;
    
    // printer(a, 'a', 0);
        
    // while(is_sorted(a))
    // {
    mid_av = min_max(a);
    while(ft_lstsize(*a) > 3)
    {
        if ((*a)->content < mid_av)
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
        indexing(a, b);
        get_target(a, b);
    }
    // printer(a, 'a', 1);
    // printer(b, 'b', 1);
    // ft_printf("mid av -> %d\nsize -> %d\n", mid_av, ft_lstsize(*a));
    sortingt_list(a, b);
    printer(a, 'a', 1);
    printer(b, 'b', 1);
    indexing(a, b);

    printer(a, 'a', 1);
    printer(b, 'b', 1);
    // }
}
