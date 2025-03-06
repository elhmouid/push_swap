/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hmo <moel-hmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 22:42:58 by moel-hmo          #+#    #+#             */
/*   Updated: 2025/03/06 00:36:54 by moel-hmo         ###   ########.fr       */
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
		if (str[index] == 32 || str[index] >= 9 && str[index] <= 13)
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
int     check_str(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+'
            && !ft_isspace(str[i]))
            return (1);
        i++;
    }
    return (0);
}

void	parsing(char **av)
{
	int i;
	int j;
	
	i = 0;

	while (av[i])
    {
        
        printf("%s ---- %d\n", av[i], check_str(av[i]));
        i++;
    }
}