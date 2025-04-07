/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hmo <moel-hmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 00:01:57 by moel-hmo          #+#    #+#             */
/*   Updated: 2025/04/08 00:52:32 by moel-hmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack, char stack_name)
{
	t_list	*first;
	t_list	*second;
	
	if (!stack || !*stack || !(*stack)->next)
		return;
	first = *stack;
	second = first->next;

	first->next = second->next;
	second->next = first;
	*stack = second;

	if (stack_name == 'a')
		ft_putstr_fd("sa\n", 1);
	else if (stack_name == 'b')
		ft_putstr_fd("sb\n", 1);
}

void	swap_both(t_list **stack_a, t_list **stack_b)
{
	if ((!stack_a || !*stack_a || !(*stack_a)->next) &&
		(!stack_b || !*stack_b || !(*stack_b)->next))
		return;
	swap(stack_a, 0);
	swap(stack_b, 0);
	ft_putstr_fd("ss\n", 1);
}

void	push(t_list **src, t_list **dst, char dst_name)
{
	t_list	*tmp;
	
	if (!src || !*src)
		return;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
	
	if (dst_name == 'a')
		ft_putstr_fd("pa\n", 1);
	else if (dst_name == 'b')
		ft_putstr_fd("pb\n", 1);
}

// Basic stack operation: rotate the stack
void	rotate(t_list **stack, char stack_name)
{
	t_list	*first;
	t_list	*last;
	
	if (!stack || !*stack || !(*stack)->next)
		return;
	first = *stack;
	last = *stack;
	
	while (last->next)
		last = last->next;
		
	*stack = first->next;
	first->next = NULL;
	last->next = first;
	
	if (stack_name == 'a')
		ft_putstr_fd("ra\n", 1);
	else if (stack_name == 'b')
		ft_putstr_fd("rb\n", 1);
}

// Rotate both stacks
void	rotate_both(t_list **stack_a, t_list **stack_b)
{
	if ((!stack_a || !*stack_a || !(*stack_a)->next) &&
		(!stack_b || !*stack_b || !(*stack_b)->next))
		return;
	
	rotate(stack_a, 0);
	rotate(stack_b, 0);
	ft_putstr_fd("rr\n", 1);
}