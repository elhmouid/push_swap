/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hmo <moel-hmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:45:36 by moel-hmo          #+#    #+#             */
/*   Updated: 2025/04/10 00:37:31 by moel-hmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_stack(t_list **stack)
{
	t_list *current;
	t_list *next;
	
	if (!stack || !*stack)
		return;
		
	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int	size;
	
	size = stack_size(*stack_a);
	
	// If already sorted, do nothing
	if (is_sorted(*stack_a))
		return;
	
	// Different sorting strategies based on stack size
	if (size <= 5)
		sort_small(stack_a, stack_b, size);
	else
		sort_large(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;
	
	stack_a = NULL;
	stack_b = NULL;
	if (ac <= 1)
		return (0);
	
	if (basic_parsing(av + 1))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	i = 1;
	while (i < ac)
	{
		parse_args(av[i], &stack_a);
		i++;
	}
	
	if (check_integers(stack_a) || is_duplicate(stack_a))
	{
		ft_putstr_fd("Error\n", 2);
		free_stack(&stack_a);
		return (1);
	}
	
	sort_stack(&stack_a, &stack_b);
	
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
