/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hmo <moel-hmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 21:47:23 by moel-hmo          #+#    #+#             */
/*   Updated: 2025/04/11 22:18:50 by moel-hmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list **stack)
{
	t_list	*current;
	t_list	*next;

	if (!stack || !*stack)
		return ;
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
	if (is_sorted(*stack_a))
		return ;
	if (size <= 5)
		sort_small(stack_a, stack_b, size);
	else
	{
		index_stack(*stack_a);
		first_step(stack_a, stack_b);
		push_back_to_a(stack_a, stack_b);
	}
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
		ft_error("Error");
	i = 0;
	while (i++ < ac)
		parse_args(av[i], &stack_a);
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
