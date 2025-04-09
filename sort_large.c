/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hmo <moel-hmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 00:34:56 by moel-hmo          #+#    #+#             */
/*   Updated: 2025/04/10 00:35:50 by moel-hmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Get index of value in sorted array
int	get_index(long *sorted, long value, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

// Create sorted array from stack
long	*create_sorted_array(t_list *stack, int size)
{
	long	*arr;
	t_list	*current;
	int		i;
	int		j;
	long	temp;

	arr = malloc(sizeof(long) * size);
	if (!arr)
		return (NULL);
	
	current = stack;
	i = 0;
	while (current)
	{
		arr[i++] = current->value;
		current = current->next;
	}
	
	// Bubble sort the array
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	
	return (arr);
}

// Sort large stack using radix sort (bit manipulation)
void	sort_large(t_list **stack_a, t_list **stack_b)
{
	int		size;
	int		max_bits;
	int		i;
	int		j;
	long	*sorted;
	t_list	*current;
	
	size = stack_size(*stack_a);
	sorted = create_sorted_array(*stack_a, size);
	if (!sorted)
		return;
	
	// Replace values with their indices
	current = *stack_a;
	while (current)
	{
		current->value = get_index(sorted, current->value, size);
		current = current->next;
	}
	free(sorted);
	
	// Calculate max bits needed
	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	
	// Perform radix sort
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			// If bit is 0, push to stack_b, else rotate stack_a
			if (((*stack_a)->value >> i) & 1)
				rotate(stack_a, 'a');
			else
				push(stack_a, stack_b, 'b');
			j++;
		}
		
		// Push all elements back to stack_a
		while (*stack_b)
			push(stack_b, stack_a, 'a');
		
		i++;
	}
}