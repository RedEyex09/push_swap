/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:38:46 by hel-magh          #+#    #+#             */
/*   Updated: 2024/02/15 12:25:27 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void printer(t_list **t, int s, int i)
{
    t_list *lst;
    if (i == 0)
    {lst = NULL;
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
            ft_printf("stack a -> %d index -> %d median -> %d\n", lst->content, lst->index, lst->median);
            lst = lst->next;
        }
    }
    if (s == 'b')
    {
        while (lst)
        {
            ft_printf("stack b -> %d index -> %d median -> %d\n", lst->content, lst->index, lst->median);
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
void stacks(t_list **a, t_list **b)
{
    int mid_av;
    
    printer(a, 'a', 0);
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
        
    }
    printer(a, 'a', 1);
    printer(b, 'b', 1);
    ft_printf("mid av -> %d\nsize -> %d\n", mid_av, ft_lstsize(*a));

    

     

    
    
}
