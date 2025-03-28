/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hmo <moel-hmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 22:42:58 by moel-hmo          #+#    #+#             */
/*   Updated: 2025/03/28 18:16:52 by moel-hmo         ###   ########.fr       */
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

int	check_white_spaces(char **av)
{
	int i = 0, j = 0;

	while (av[i])
	{
		j = 0;
		while (ft_isspace(av[i][j]))
			j++;
		if (av[i][j] == '\0')
		{
			return (1);
		}
		i++;
	}
	i = 1;
	j = 0;
	while (av[i])
	{
		while(av[i][j])
		{
			if((av[i][j] >= '0' && av[i][j] <= '9') || !(av[i][j] == ' '))
			{
				printf("❌ Caractère invalide détecté : av[%d] = \"%s\" (av[%d][%d] = '%c')\n", i, av[i], i, j, av[i][j]);
				return 1;
			}
			j++;
		}
		j =0;
		i++;
	}
	return (0);
}
void	parsing(char **av)
{
	if (check_white_spaces(av))
		ft_error("Error");
}