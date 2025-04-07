/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hmo <moel-hmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 22:42:58 by moel-hmo          #+#    #+#             */
/*   Updated: 2025/04/07 20:36:10 by moel-hmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long ft_atoi(char *str)
{
    long result;
    int sign;
    int i;
    int j;
    char digit_str[20];

    result = 0;
    sign = 1;
    i = 0;
    j = 0;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] == '0')
        i++;
    while (str[i] >= '0' && str[i] <= '9' && j < 19)
        digit_str[j++] = str[i++];
    digit_str[j] = '\0';
    if ((sign == 1 && ft_strlen(digit_str) > 10) || 
        (sign == -1 && ft_strlen(digit_str) > 10))
		ft_error("Error");
    i = 0;
    while (digit_str[i++])
        result = (result * 10) + (digit_str[i] - '0');
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
		if (ft_isdigit(str[i - 1]) && (str[i] == '+'
			|| str[i] == '-'))
			return (1);
		i++;
	}
	return (0);
}

void	parse_args(char *arg, t_list **stack)
{
	char	**split;
	int		i;
	long	value;
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

// static int	count_digits(long value)
// {
// 	int	len;

// 	len = 0;
// 	if (value == 0)
// 		return (1);
// 	if (value < 0)
// 	{
// 		len++;
// 		value *= -1;
// 	}
// 	while (value > 0)
// 	{
// 		value /= 10;
// 		len++;
// 	}
// 	return (len);
// }

// int	check_len(t_list *stack)
// {
// 	t_list	*current;
// 	int		len;

// 	current = stack;
// 	while (current)
// 	{
// 		len = count_digits(current->value);
// 		if ((current->value < 0 && len > 11) || 
// 			(current->value >= 0 && len > 10))
// 			return (1);
// 		current = current->next;
// 	}
// 	return (0);
// }

int check_integers(t_list *stack)
{
    t_list *current;
    long	value;

    current = stack;
    while (current)
    {
        value = current->value;
        if (value < INT_MIN || value > INT_MAX)
            return (1);
        current = current->next;
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
int	is_duplicate(t_list *stack)
{
	t_list *current;
	t_list *check;
	
	current = stack;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->value == check->value)
				return (1);
			check = check->next;
		}
		current = current->next;
	}
	return (0);
}
