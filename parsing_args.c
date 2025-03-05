/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hmo <moel-hmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 22:42:58 by moel-hmo          #+#    #+#             */
/*   Updated: 2025/03/05 23:12:32 by moel-hmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char **ft_split(int ac, char **av)
{
	
}


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
		if (str[index] == '-')
			sign = -1;
	index++;
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

void	parsing(int ac, char **av)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	if (ac < 2)
		exit(0);
	while (av[i++])
		while (av[i][j++])
			if (!(ft_isdigit(av[i][j]) || av[i][j] != '+' || av[i][j] != '-' || av[i][j] != '"'))
				fail_error("Error : Please double check the arguments");
	i = 0;
	while (av[i][j])
	{
		if (av[i][j] != '"')
		ft_atoi(av[i]);
	i++;
	}
}