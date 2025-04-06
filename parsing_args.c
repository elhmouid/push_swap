/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hmo <moel-hmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 22:42:58 by moel-hmo          #+#    #+#             */
/*   Updated: 2025/04/06 17:10:50 by moel-hmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	overflow_check(int sign)
{
	if (sign == 1)
		return (-1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (!str[i])
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > (LONG_MAX - (str[i] - '0')) / 10)
			return (overflow_check(sign));
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int ft_isspace(char c)
{
    return (c == 32 || c == '\t');
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
		i++;
	}
	return (0);
}

void	parse_args(char *arg, t_list **stack)
{
	char	**split;
	int		i;
	int		value;
	t_list	*node;

	i = 0;
	split = ft_split(arg);
	if (!split || !stack)
		return;
	while (split[i])
	{
		value = ft_atoi(split[i]);
		node = new_node(value);
		if (!node)
		{
			while (split[i])
				free(split[i++]);
			free(split);
			return;
		}
		add_back(stack, node);
		free(split[i]);
		i++;
	}
	free(split);
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
	i = 1;
	// while (i < ac)
	// {
	// 	i++;
	// }
	
	return (0);
}
