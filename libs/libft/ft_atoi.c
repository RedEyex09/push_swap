/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:18:14 by hel-magh          #+#    #+#             */
/*   Updated: 2024/02/18 22:20:15 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	check(size_t res, int n)
{
	if ((res > 2147483647 && n == 1) || (res > 2147483648 && n == -1))
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}

long long	ft_atoi(const char *str)
{
	size_t	i;
	int		n;
	size_t	res;

	i = 0;
	n = 1;
	res = 0;
	while (str[i] == ' ' || ('\t' <= str[i] && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			n = n * (-1);
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + str[i] - '0';
		check(res, n);
		i++;
	}
	return (res * n);
}
