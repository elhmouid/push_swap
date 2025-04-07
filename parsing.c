/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hmo <moel-hmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 22:42:58 by moel-hmo          #+#    #+#             */
/*   Updated: 2025/04/07 21:11:25 by moel-hmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_args(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '+'
			&& str[i] != '-' && !ft_isspace(str[i]))
			return (1);
		if ((str[i] == '+' && str[i + 1] == '+')
			|| (str[i] == '-' && str[i + 1] == '-'))
			return (1);
		if ((str[i] == '+' && str[i + 1] == '-')
			|| (str[i] == '-' && str[i + 1] == '+'))
			return (1);
		if (ft_isdigit(str[i - 1]) && (str[i] == '+'
			|| str[i] == '-'))
			return (1);
		i++;
	}
	return (0);
}

int	basic_parsing(int ac, char **av)
{
	int	i;
	t_list *stack;
	
	i = 0;
	stack = NULL;
	while (av[i])
	{
		if (empty_string(av[i]))
			return (1);
		if (check_args(av[i]))
			return (1);
		i++;
	}
	return (0);
}
int	empty_string(char *str)
{
	int	i;
	
	i = 0;
	while (str[i] && ft_isspace(str[i]))
	{
		i++;
	}
	if (str[i] == '\0')
	{
		return (1);
	}
	return (0);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int ft_isspace(char c)
{
    return (c == 32 || c == '\t');
}
