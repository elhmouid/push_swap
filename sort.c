/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hmo <moel-hmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 00:11:18 by moel-hmo          #+#    #+#             */
/*   Updated: 2025/04/08 00:19:12 by moel-hmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_list **stack)
{
	if ((*stack)->value > (*stack)->next->value)
		swap(stack, 'a');
}

void	sort_three(t_list **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->value;
	second = (*stack)->next->value;
	third = (*stack)->next->next->value;

	if (first > second && second < third && first < third)
		swap(stack, 'a');
	else if (first > second && second > third)
	{
		swap(stack, 'a');
		reverse_rotate(stack, 'a');
	}
	else if (first > second && second < third && first > third)
		rotate(stack, 'a');
	else if (first < second && second > third && first < third)
	{
		swap(stack, 'a');
		rotate(stack, 'a');
	}
	else if (first < second && second > third && first > third)
		reverse_rotate(stack, 'a');
}

int	find_position(t_list *stack, long value)
{
	int		pos;
	t_list	*current;

	pos = 0;
	current = stack;
	while (current)
	{
		if (current->value == value)
			return (pos);
		pos++;
		current = current->next;
	}
	return (-1);
}

void	move_min_to_top(t_list **stack_a)
{
	t_list	*min;
	int		min_pos;
	int		size;

	min = find_min(*stack_a);
	min_pos = find_position(*stack_a, min->value);
	size = stack_size(*stack_a);

	if (min_pos <= size / 2)
	{
		// Move up using rotate
		while (min_pos-- > 0)
			rotate(stack_a, 'a');
	}
	else
	{
		// Move up using reverse rotate
		while (min_pos++ < size)
			reverse_rotate(stack_a, 'a');
	}
}

// Sort small stack (up to 5 elements)
void	sort_small(t_list **stack_a, t_list **stack_b, int size)
{
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size <= 5)
	{
		// Push smallest elements to stack_b
		while (stack_size(*stack_a) > 3)
		{
			move_min_to_top(stack_a);
			push(stack_a, stack_b, 'b');
		}
		
		// Sort remaining 3 elements in stack_a
		sort_three(stack_a);
		
		// Push back elements from stack_b
		while (*stack_b)
			push(stack_b, stack_a, 'a');
	}
}
