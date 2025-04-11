/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hmo <moel-hmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 22:15:58 by moel-hmo          #+#    #+#             */
/*   Updated: 2025/04/11 22:16:11 by moel-hmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_position_max(t_list *stack)
{
	int		max_value;
	t_list	*tmp;

	max_value = find_max_value(stack);
	tmp = stack;
	while (tmp)
	{
		if (tmp->value == max_value)
			return (tmp->position);
		tmp = tmp->next;
	}
	return (-1);
}

void	move_max_to_top(t_list **stack_b, int max_pos, int size)
{
	if (max_pos <= size / 2)
	{
		while (max_pos-- > 0)
			rotate(stack_b, 'b');
	}
	else
	{
		while (max_pos++ < size)
			reverse_rotate(stack_b, 'b');
	}
}

void	push_back_to_a(t_list **stack_a, t_list **stack_b)
{
	int	b_size;
	int	max_pos;

	while (*stack_b)
	{
		b_size = stack_size(*stack_b);
		assign_position(*stack_b);
		max_pos = find_position_max(*stack_b);
		move_max_to_top(stack_b, max_pos, b_size);
		push(stack_b, stack_a, 'a');
	}
}
