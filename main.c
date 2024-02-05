/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 10:09:04 by hel-magh          #+#    #+#             */
/*   Updated: 2024/02/05 12:34:16 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//free functions
void	ft_free(char *str)
{
	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
}

void	*ft_free_double(char **str, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

// exit program and diplay erro
void	ft_exit(int i)
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
int	ft_pn(char c)
{
	return (c == '+' || c == '-');
}

int ft_str_degit(char *s)
{
	int i = 0;
	while (s[i])
	{
		if(ft_isdigit(s[i]) || ft_pn(s[i]))
		{
			if(ft_pn(s[i + 1]))
				return (0);
			i++;
		}
		else
			return (0);
	}
	return(1);
}
/* this function check the content of
 all argument while looping on every argument*/
void	ft_check_2(t_arg_chek *arg, int a)
{
	arg->i = 0;
	arg->l = 0;
	int k = 0;
	while (arg->num[arg->i])
	{
		arg->l = 0;
		if (a == 0)
		{
			while (arg->num[arg->i][arg->l])
			{
				if (ft_isdigit(arg->num[arg->i][arg->l])
					|| ft_pn(arg->num[arg->i][arg->l]))
				{
					if (ft_pn(arg->num[arg->i][arg->l + 1]))
						ft_exit(0);
				}
				else
					ft_exit(0);
				arg->l++;
			k = ft_atoi(arg->num[arg->i]);
			}
		}
		else if (ft_str_degit(arg->num[arg->i]))
			k = ft_atoi(arg->num[arg->i]);
		else
			ft_exit(0);
		ft_printf("%d\n",k);
		arg->i++;
	}
}
void	ft_check(char **av)
{
	t_arg_chek	arg;

	arg.j = 1;
	while (av[arg.j])
	{
		if(ft_strchr(av[arg.j], ' '))
		{
			arg.i = 0;
			while(av[arg.j][arg.i])
			{
				if (av[arg.j][arg.i] == ' ' && av[arg.j][arg.i + 1] == ' ')
					ft_exit(0);
				arg.i++;
			}
			arg.num = ft_split(av[arg.j], ' ');
			ft_check_2(&arg, 0);
			arg.j++;
		}
		else
		{
			arg.num = &av[arg.j];
			ft_check_2(&arg, 1);
			break ;
		}
	}
}

// void f(void)
// {
// 	system("leaks push_swap");
// }
int	main(int ac, char **av) // " 18 12" "15 17 30"
{
	// atexit(f);
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (0);
	if (ac >= 2)
	{
		ft_check(av);
	}
	return (0);
}

