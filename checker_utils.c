/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:20:01 by hel-magh          #+#    #+#             */
/*   Updated: 2024/02/23 19:16:35 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void is_valid(t_list **a, t_list **b, char *rule)
{
    if(ft_strncmp(rule, "pa\n", 3) == 0)
        pa(a, b, 0);
    else if(ft_strncmp(rule, "pb\n", 3) == 0)
        pb(a, b, 0);
    else if(ft_strncmp(rule, "ss\n", 3) == 0)
        ss(a, b, 0);
    else if(ft_strncmp(rule, "sa\n", 3) == 0)
        sa(a, 0);
    else if(ft_strncmp(rule, "sb\n", 3) == 0)
        sb(b, 0);
    else if(ft_strncmp(rule, "rr\n", 3) == 0)
        rr(a, b, 0);
    else if(ft_strncmp(rule, "rb\n", 3) == 0)
        rb(b, 0);
    else if(ft_strncmp(rule, "ra\n", 3) == 0)
        ra(a, 0);
    else if(ft_strncmp(rule, "rra\n", 3) == 0)
        rra(a, 0);
    else if(ft_strncmp(rule, "rrb\n", 3) == 0)
        rrb(a, 0);
    else if(ft_strncmp(rule, "sa\n", 3) == 0)
        rrr(a, b, 0);
    else
       ft_exit();   
}
