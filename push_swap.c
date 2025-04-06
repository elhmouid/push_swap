/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hmo <moel-hmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:45:36 by moel-hmo          #+#    #+#             */
/*   Updated: 2025/04/06 16:32:10 by moel-hmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int main(int ac, char **av)
{
	int	i;
	t_list *stack;

	stack = NULL;
	if (ac <= 1)
		return (0);
	if (basic_parsing(ac, ++av))
	{
		puts("Error");
		return (1);
	}
	i = 1;
	while (i < ac)
	{
		parse_args(av[i], &stack);
		i++;	
	}
	// t_list *tmp = stack;
	// while (tmp)
	// {
	// 	tmp = tmp->next;
	// 	printf("%d\n", tmp->value);
	// }
	return (0);
}
