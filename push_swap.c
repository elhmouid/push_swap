/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hmo <moel-hmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:45:36 by moel-hmo          #+#    #+#             */
/*   Updated: 2025/04/06 13:06:29 by moel-hmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int main(int ac, char **av)
{
	// t_stack *a;
	// t_stack *b

	if (ac <= 1)
		return (0);
	if (basic_parsing(ac, ++av))
	{
		puts("Error");
		return (1);
	}
	return (0);
	// printf("%d  ====== %s \n", ac, av[0]);
}