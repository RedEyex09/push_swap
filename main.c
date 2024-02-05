/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 10:09:04 by hel-magh          #+#    #+#             */
/*   Updated: 2024/02/05 16:24:57 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// free functions
void ft_free(char *str)
{
	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
}

void *ft_free_double(char **str)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

// exit program and diplay erro
void ft_exit(int i)
{
	if (i == 0)
	{
		ft_printf("Error\n");
		exit(0);
	}
	else
	{
		ft_printf("Error\n");
		exit(1);
	}
}

// chaeck the content of the arguments
int ft_pn(char c)
{
	return (c == '+' || c == '-');
}

void ft_str_pn(char *s)
{
	int i;

	i = 0;
	if (ft_pn(s[i]) && s[i + 1] == '\0')
		ft_exit(0);
}
/* this function check the content of
 all argument while looping on every argument*/

void ft_check_3(t_arg_chek *arg)
{
	while (arg->num[arg->i][arg->l])
	{
		if (ft_isdigit(arg->num[arg->i][arg->l]) || ft_pn(arg->num[arg->i][arg->l]))
		{
			if (ft_pn(arg->num[arg->i][arg->l + 1]))
				ft_exit(0);
		}
		else
			ft_exit(0);
		arg->l++;
	}
}
// void ft_number_listing(int a)
// {
// 	t_list num;

// }
void ft_check_2(t_arg_chek *arg)
{
	arg->i = 0;
	arg->l = 0;
	int k = 0;
	while (arg->num[arg->i])
	{
		arg->l = 0;
		ft_str_pn(arg->num[arg->i]);
		ft_check_3(arg);
		k = ft_atoi(arg->num[arg->i]);
		ft_printf("%d\n", k);
		arg->i++;
	}
}

void ft_check(char **av)
{
	t_arg_chek arg;

	arg.j = 1;
	while (av[arg.j])
	{
		if(ft_strncmp(av[arg.j],"", 1) == 0)
			ft_exit(0);
		arg.num = ft_split(av[arg.j], ' ');
		ft_check_2(&arg);
		ft_free_double(arg.num);
		arg.j++;
	}
}

void f(void)
{
	system("leaks push_swap");
}
int main(int ac, char **av)
{
	atexit(f);
	if (ac == 1 || (ac == 2))
		return (0);
	if (ac >= 2)
	{
		ft_check(av);
	}
	return (0);
}
