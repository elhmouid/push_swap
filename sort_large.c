#include "push_swap.h"
#include <stdio.h>

void index_stack(t_list *stack)
{
    int s = stack_size(stack);
    int index = 0;
    t_list *tmp = stack;
    t_list *tr = NULL;

    while (s)
    {
        int min;

        min = INT_MAX;
        tmp = stack;
        while (tmp)
        {
            if (tmp->index == -1)
            {
                if (tmp->value <= min)
                {
                    tr = tmp;
                    min = tmp->value;
                }
            }
            tmp = tmp->next;
        }
        tr->index = index;
        index++;
        s--;
    }
}

void first_step(t_list **stack_a, t_list **stack_b)
{
    int i = 0;
    // int size = stack_size(*stack_a);
    // printf("sizee  %d\n", size);
	// t_list *tmp = *stack_a;
	int range = 16;
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
	int i = 0;
	t_list *tmp = stack_b;
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

int		find_position_max(t_list *stack)
{
	int max_value = find_max_value(stack);
	t_list *tmp = stack;

	while (tmp)
	{
		if (tmp->value == max_value)
			return tmp->position;
		tmp = tmp->next;
	}
	return (-1);
}

void push_back_to_a(t_list **stack_a, t_list **stack_b)
{
	int b_size;
    
    while (*stack_b)
    {
		b_size = stack_size(*stack_b);
		assign_position(*stack_b);
		int max_pos = find_position_max(*stack_b);
		// printf("sizeeeeeee   %d\n", b_size);
        if (max_pos <= b_size / 2)
        {
            while (max_pos > 0)
            {
                rotate(stack_b, 'b');
                max_pos--;
            }
        }
        else
        {
            while (max_pos < b_size)
            {
                reverse_rotate(stack_b, 'b');
                max_pos++;
            }
        }
        push(stack_b, stack_a, 'a');
		
    }
}
void print_stack(t_list *stack)
{
    t_list *current = stack;
    
    while (current)
    {
        fprintf(stderr, "Value: %ld, Index: %d\n", current->value, current->index);
        current = current->next;
    }
}

