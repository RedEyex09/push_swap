/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 10:35:17 by hel-magh          #+#    #+#             */
/*   Updated: 2024/02/22 19:32:13 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libs/ft_printf/ft_printf.h"
# include "./libs/libft/libft.h"
# include <fcntl.h>
# include <limits.h>

typedef struct arg_chek
{
	int		i;
	int		j;
	int		l;
	char	**n;
	int		min;
	int		max;
}	t_arg_chek;

typedef struct s_list
{
	int				content;
	int				index;
	int				median;
	int				target;
	int				cost;
	int				index_value;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst);
void	ft_free(char *str);
void	*ft_free_double(char **str);
void	ft_exit(void);
int		ft_pn(char c);
void	ft_str_pn(char *s);
void	add_num(t_list **head, int n);
int		duplicate(int n, t_list *head);
void	empty(t_arg_chek *num, char **av);
int		max_check(int i, long long k);
void	stacks(t_list **a, t_list **b);
void	push(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	ss(t_list **a, t_list **b);
void	sb(t_list **b, int i);
void	sa(t_list **a, int i);
void	rr(t_list **a, t_list **b);
void	rb(t_list **b, int i);
void	ra(t_list **a, int i);
void	rra(t_list **a, int i);
void	rrb(t_list **b, int i);
void	rrr(t_list **a, t_list **b);
void	sort_three(t_list **lst);
int		is_sorted(t_list **a);
void	index_value(t_list *stacka);
int		is_sorted(t_list **a);
int		low_cost_index(t_list **b);
void	indexer(t_list **m);
void	indexing(t_list **a, t_list **b);
int		cost(t_list **a, int target);
void	get_cost(t_list **a, t_list **b);
void	get_target(t_list **a, t_list **b);
int		min_max(t_list **a, int i);
void	sort_three(t_list **lst);

#endif