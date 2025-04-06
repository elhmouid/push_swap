/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hmo <moel-hmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 22:42:58 by moel-hmo          #+#    #+#             */
/*   Updated: 2025/04/06 15:27:00 by moel-hmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str)
{
	int index;
	int sign;
	int number;

	index = 0;
	sign = 1;
	number = 0;
	if (!str[index])
		return (0);
	while (str[index])
		if (str[index] == 32 || (str[index] >= 9 && str[index] <= 13))
			index++;
	if (str[index] == '+' || str[index] == '-')
    {
		if (str[index] == '-')
			sign = -1;
	    index++;
    }
	while (str[index])
	{
		if(str[index] >= '0' && str[index] <= '9')
			number = number * 10 + (str[index] - 48);
		index++;
	}
	return (number * sign);
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
		i++;
	}
	return (0);
}

void	parse_args(char *arg, t_list **stack)
{
	char	**split;
	int		i = 0;
	int		value;
	t_list	*node;

	split = ft_split(arg);
	if (!split)
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
