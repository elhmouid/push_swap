/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hmo <moel-hmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:03:14 by moel-hmo          #+#    #+#             */
/*   Updated: 2025/04/10 23:15:30 by moel-hmo         ###   ########.fr       */
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
    while (str[i] == '0')
        i++;
    while (str[i] >= '0' && str[i] <= '9' && j < 19)
    {
        digit_str[j] = str[i];
        i++;
        j++;
    }
    digit_str[j] = '\0';
    if ((sign == 1 && ft_strlen(digit_str) > 10) || 
        (sign == -1 && ft_strlen(digit_str) > 10))
    {
        if (sign == 1)
            return (LONG_MAX);
        else
            return (LONG_MIN);
    }
    i = 0;
    while (digit_str[i])
    {
        if (result > (LONG_MAX - (digit_str[i] - '0')) / 10)
        {
            if (sign == 1)
                return (LONG_MAX);
            else
                return (LONG_MIN);
        }
        result = (result * 10) + (digit_str[i] - '0');
        i++;
    }
    return (result * sign);
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
