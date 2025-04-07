/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hmo <moel-hmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:45:36 by moel-hmo          #+#    #+#             */
/*   Updated: 2025/04/07 23:55:25 by moel-hmo         ###   ########.fr       */
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

int main(int ac, char **av)
{
    t_list *stack_a;
    int i;
    
    stack_a = NULL;
    if (ac <= 1)
        return (0);
    
    if (basic_parsing(++av))
    {
        ft_putstr_fd("Error\n", 2);
        return (1);
    }
    i = 0;
    while (i < ac)
    {
        parse_args(av[i], &stack_a);
        i++;
    }
    // check_len(stack_a);
    if (check_integers(stack_a) || is_duplicate(stack_a))
	{
		ft_putstr_fd("Error\n", 2);
		free_stack(&stack_a);
		return (1);
	}
	t_list *tmp;
	tmp = stack_a;
	while (tmp)
	{
		printf("%ld\t\n", tmp->value );
		tmp = tmp->next;
	}
	free_stack(&stack_a);
    return (0);
}
