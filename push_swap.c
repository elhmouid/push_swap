/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hmo <moel-hmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:45:36 by moel-hmo          #+#    #+#             */
/*   Updated: 2025/03/27 22:11:12 by moel-hmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int main(int ac, char **av)
{
	if (ac < 2)
		ft_error("You need more parameters!!");
	parsing(av);
	return (0);
	// printf("%d  ====== %s \n", ac, av[0]);
}