/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hmo <moel-hmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 22:05:09 by moel-hmo          #+#    #+#             */
/*   Updated: 2025/04/11 22:15:56 by moel-hmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_index(t_list *stack, int index)
{
	t_list	*tmp;
	t_list	*target;
	int		min;

	min = INT_MAX;
	target = NULL;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index == -1 && tmp->value <= min)
		{
			min = tmp->value;
			target = tmp;
		}
		tmp = tmp->next;
	}
	if (target)
		target->index = index;
}

void	index_stack(t_list *stack)
{
	int	size;
	int	index;

	size = stack_size(stack);
	index = 0;
	while (index < size)
	{
		update_index(stack, index);
		index++;
	}
}

void	first_step(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	range;

	i = 0;
	range = 16;
	if (stack_size(*stack_a) > 100)
		range = 32;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			push(stack_a, stack_b, 'b');
			i++;
		}
		else if ((*stack_a)->index <= i + range)
		{
			push(stack_a, stack_b, 'b');
			rotate(stack_b, 'b');
			i++;
		}
		else
			rotate(stack_a, 'a');
	}
}

void	assign_position(t_list *stack_b)
{
	int		i;
	t_list	*tmp;

	tmp = stack_b;
	i = 0;
	while (tmp)
	{
		tmp->position = i;
		i++;
		tmp = tmp->next;
	}
}

int	find_max_value(t_list *stack)
{
	int		pos;
	t_list	*current;

	pos = INT_MIN;
	current = stack;
	while (current)
	{
		if (current->value > pos)
			pos = current->value;
		current = current->next;
	}
	return (pos);
}
