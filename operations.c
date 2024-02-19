/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:38:46 by hel-magh          #+#    #+#             */
/*   Updated: 2024/02/19 20:35:08 by hel-magh         ###   ########.fr       */
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
            ft_printf("stack a -> %d index ->  %d cost -> %d median ->%d index_value : %d\n", lst->content, lst->index, lst->cost, lst->median, lst->index_value);
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
int min_max(t_list **a, int i)
{
    t_list *mm;
    int     min = 0;
    int     max = 0;
    int     max_re = 0;
    int     min_re = 0;

    mm = *a;
    while(mm)
    {
        if(!min || min > mm->content)
        {
            min = mm->content;
            min_re = mm->content; 
        }
        if (!max || max < mm->content)
        {
            max = mm->content;
            max_re = mm->content; 
        }
        mm = mm->next;
    }
    if(i == 1)
        return(min);
    if (i == 2)
        return(max);
    if (i == 3)
        return(min_re);
    if (i == 4)
        return(max_re);
    return((min + max)/ 2);
}
void sort_three(t_list **lst)
{
   if ((*lst)->content < (*lst)->next->content
        && (*lst)->content < (*lst)->next->next->content
        && (*lst)->next->content > (*lst)->next->next->content)
        rra(lst, 1);
    if ((*lst)->content > (*lst)->next->content
        && (*lst)->content < (*lst)->next->next->content)
        sa(lst, 1);
    if ((*lst)->content > (*lst)->next->content
        && (*lst)->next->content > (*lst)->next->next->content)
        sa(lst, 1);
    if ((*lst)->content < (*lst)->next->content
        && (*lst)->next->next->content < (*lst)->content)
        rra(lst, 1);
    if ((*lst)->content > (*lst)->next->content
        && (*lst)->next->content < (*lst)->next->next->content)
        ra(lst, 1);
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
        else
            lst->median = 0;
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
        else
            lst->median = 0;
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
        if(stack_a->content == target)
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
    int min = min_max(a, 1);
    int max = min_max(a, 2);

    stack_b = *b;  
    while(stack_b)
    {
        stack_b->target = max;
        stack_a = *a;
        while(stack_a)
        {
            if (stack_b->content >max)
            {
                stack_b->target = min;
                break;
            }
            else if (stack_a->content > stack_b->content && stack_a->content < stack_b->target)
            {
                stack_b->target = stack_a->content;
            }
            stack_a = stack_a->next;
        }
        stack_b = stack_b->next;
    }
    indexing(a, b);
    get_cost(a, b);
    // printer(a, 'a', 1);
    // printer(b, 'b', 1);
    // exit(0);
}

int low_cost_index(t_list **b)
{
    t_list *stack_b;

    int tmp = 0;
    int cost = 0;
    stack_b = *b; 
    cost = stack_b->cost;
    tmp = stack_b->content;
    // tmp = min_max(b, 2);
    while(stack_b)
    {
        if (stack_b->cost < cost)
        {
            tmp = stack_b->content;
            cost = stack_b->cost;
        }
        // ft_printf("stack_b content %d and it's cost %d\n", stack_b->content, stack_b->cost);
        stack_b = stack_b->next;
    }

    // ft_printf(" LOW COST :  %d\n", cost);
    return(tmp);
}
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
               
           }
           break ;
          } 

        stack_b = stack_b->next;
    }  
}

int is_sorted(t_list **a)
{
    t_list *stack_a;

    stack_a = *a;

    while (stack_a && stack_a->next)
    {
        if (stack_a->content <= stack_a->next->content)
            stack_a = stack_a->next;
        else
            return 0;
    }
    return 1;
}
void    index_value(t_list *stacka)
{
    t_list    *current_node;
    t_list    *compare_node;
    int        index;

    current_node = stacka;
    while (current_node != NULL)
    {
        compare_node = stacka;
        index = 0;
        while (compare_node != NULL)
        {
            if (current_node->content > compare_node->content)
                index++;
            compare_node = compare_node->next;
        }
        current_node->index_value = index;
        current_node = current_node->next;
    }
}
void stacks(t_list **a, t_list **b)
{
    int mid_av;
    t_list *tmp;
    
    if(is_sorted(a))
        exit(0);
    tmp = NULL;
    mid_av = min_max(a, 0);
    while(ft_lstsize(*a) > 3 && !is_sorted(a))
    {
        if ((*a)->content <= mid_av)
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
    while(ft_lstsize(*b) != 0)
    {
        
        indexing(a, b);
        get_target(a, b);
        // indexing(a, b);
        sortingt_list(a, b);
        pa(a, b);
        // indexing(a, b);
        // printer(a, 'a', 1);
        // printer(b, 'b', 1);
     
    }
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

        // printer(a, 'a', 1);
        // printer(b, 'b', 1);
}
