/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hmo <moel-hmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:03:14 by moel-hmo          #+#    #+#             */
/*   Updated: 2025/04/11 18:03:48 by moel-hmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	skip_whitespace_and_sign(char *str, int *sign)
{
	int	i;

	i = 0;
	*sign = 1;
	if (!str[i])
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign = -1;
		i++;
	}
	while (str[i] == '0')
		i++;
	return (i);
}

long	process_number(char *digit_str, int sign)
{
	long	result;
	int		i;

	result = 0;
	i = -1;
	if ((sign == 1 && ft_strlen(digit_str) > 10) ||
		(sign == -1 && ft_strlen(digit_str) > 10))
	{
		if (sign == 1)
			return (LONG_MAX);
		else
			return (LONG_MIN);
	}
	while (digit_str[++i])
	{
		if (result > (LONG_MAX - (digit_str[i] - '0')) / 10)
		{
			if (sign == 1)
				return (LONG_MAX);
			else
				return (LONG_MIN);
		}
		result = (result * 10) + (digit_str[i] - '0');
	}
	return (result * sign);
}

long	ft_atoi(char *str)
{
	int		i;
	int		j;
	int		sign;
	char	digit_str[20];

	i = skip_whitespace_and_sign(str, &sign);
	j = 0;
	while (str[i] >= '0' && str[i] <= '9' && j < 19)
	{
		digit_str[j] = str[i];
		i++;
		j++;
	}
	digit_str[j] = '\0';
	return (process_number(digit_str, sign));
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
