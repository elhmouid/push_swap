/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hmo <moel-hmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 00:11:05 by moel-hmo          #+#    #+#             */
/*   Updated: 2025/04/11 22:27:48 by moel-hmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_list **stack, char stack_name)
{
	t_list	*last;
	t_list	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
	if (stack_name == 'a')
		ft_putstr_fd("rra\n", 1);
	else if (stack_name == 'b')
		ft_putstr_fd("rrb\n", 1);
}

void	reverse_rotate_both(t_list **stack_a, t_list **stack_b)
{
	if ((!stack_a || !*stack_a || !(*stack_a)->next)
		&& (!stack_b || !*stack_b || !(*stack_b)->next))
		return ;
	reverse_rotate(stack_a, 0);
	reverse_rotate(stack_b, 0);
	ft_putstr_fd("rrr\n", 1);
}

int	stack_size(t_list *stack)
{
	int		size;
	t_list	*current;

	size = 0;
	current = stack;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}

int	is_sorted(t_list *stack)
{
	t_list	*current;

	if (!stack)
		return (1);
	current = stack;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

t_list	*find_min(t_list *stack)
{
	t_list	*min;
	t_list	*current;

	if (!stack)
		return (NULL);
	min = stack;
	current = stack;
	while (current)
	{
		if (current->value < min->value)
			min = current;
		current = current->next;
	}
	return (min);
}
