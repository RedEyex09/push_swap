/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:20:01 by hel-magh          #+#    #+#             */
/*   Updated: 2024/02/24 14:34:36 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	entry_validation(char *rule, t_list **a)
{

	if ((!ft_strncmp(rule, "pa\n", 3)) || (!ft_strncmp(rule, "pb\n", 3))
		|| (!ft_strncmp(rule, "ss\n", 3)) || (!ft_strncmp(rule, "sa\n", 3))
		|| (!ft_strncmp(rule, "sb\n", 3)) || (!ft_strncmp(rule, "rr\n", 3))
		|| (!ft_strncmp(rule, "rb\n", 3)) || (!ft_strncmp(rule, "ra\n", 3))
		|| (!ft_strncmp(rule, "rra\n", 4)) || (!ft_strncmp(rule, "rrb\n", 4))
		|| (!ft_strncmp(rule, "rrr\n", 4)))
		return ;
	else
	{
		free(rule);
		ft_lstclear(a);
		ft_exit();
	}
}

void	is_valid(t_list **a, t_list **b, char *rule)
{
	if (ft_strncmp(rule, "pa", 3) == 0)
		pa(a, b, 0);
	else if (ft_strncmp(rule, "pb", 3) == 0)
		pb(a, b, 0);
	else if (ft_strncmp(rule, "ss", 3) == 0)
		ss(a, b, 0);
	else if (ft_strncmp(rule, "sa", 3) == 0)
		sa(a, 0);
	else if (ft_strncmp(rule, "sb", 3) == 0)
		sb(b, 0);
	else if (ft_strncmp(rule, "rr", 3) == 0)
		rr(a, b, 0);
	else if (ft_strncmp(rule, "rb", 3) == 0)
		rb(b, 0);
	else if (ft_strncmp(rule, "ra", 3) == 0)
		ra(a, 0);
	else if (ft_strncmp(rule, "rra", 4) == 0)
		rra(a, 0);
	else if (ft_strncmp(rule, "rrb", 4) == 0)
		rrb(a, 0);
	else if (ft_strncmp(rule, "rrr", 4) == 0)
		rrr(a, b, 0);
	else
		ft_exit();
}

void	ft_exit_cheker(t_list **a)
{
	ft_lstclear(a);
	ft_exit();
}

char	*ft_buffer_fill(t_list **a)
{
	char	*line;
	char	*tmp;
	char	*s;

	line = ft_strdup("");
	if (!line)
		ft_exit_cheker(a);
	s = get_next_line(0);
	if ((!s || ft_strncmp(s, "\n", 1) == 0) && !is_sorted(a))
	{
		free(line);
		ft_exit_cheker(a);
	}
	while (s)
	{
		tmp = line;
		line = ft_strjoin(tmp, s);
		free(tmp);
		tmp = NULL;
		entry_validation(s, a);
		free(s);
		s = get_next_line(0);
	}
	return (line);
}

void	ft_reader(t_list **a, t_list **b)
{
	char	*line;
	char	**buffer;
	int		i;

	i = 0;
	line = ft_buffer_fill(a);
	buffer = ft_split(line, '\n');
	if (!buffer)
	{
		ft_lstclear(a);
		free(line);
		ft_exit();
	}
	while (buffer[i])
	{
		is_valid(a, b, buffer[i]);
		free(buffer[i]);
		i++;
	}
	// ft_lstclear(b);
	free(buffer);
	free(line);
}
