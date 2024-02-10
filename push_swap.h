/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 10:35:17 by hel-magh          #+#    #+#             */
/*   Updated: 2024/02/10 10:48:59 by hel-magh         ###   ########.fr       */
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
}	t_arg_chek;

typedef struct s_list
{
	int				content;
	struct s_list	*next;
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

#endif