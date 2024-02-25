/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:39:23 by hel-magh          #+#    #+#             */
/*   Updated: 2024/02/25 09:19:27 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_free(char *str)
{
	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
}

void	*ft_free_double(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

void	ft_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	ft_pn(char c)
{
	return (c == '+' || c == '-');
}

void	ft_str_pn(char *s)
{
	int	i;

	i = 0;
	if (ft_pn(s[i]) && (s[i + 1] == '\0'
			|| ft_pn(s[i + 1])))
		ft_exit();
}
