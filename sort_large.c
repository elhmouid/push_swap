#include "push_swap.h"

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
    int size = stack_size(*stack_a);
    
    while (size > 0)
    {
        if ((*stack_a)->index <= i)
        {
            push(stack_a, stack_b, 'b');
            i++;
        }
        else if ((*stack_a)->index <= i + 15)
        {
            push(stack_a, stack_b, 'b');
            rotate(stack_b, 'b');
            i++;
        }
        else
            rotate(stack_a, 'a');
        size--;
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
int	find_position_max(t_list *stack)
{
	int		pos;
	t_list	*current;

	pos = 0;
	current = stack;
	while (current)
	{
		if (current->value)
			return (pos);
		pos++;
		current = current->next;
	}
	return (-1);
}

void push_back_to_a(t_list **stack_a, t_list **stack_b)
{
    int max_index;
    int max_pos;
    int b_size;
    
    while (*stack_b)
    {
        b_size = stack_size(*stack_b);
        
        t_list *current = *stack_b;
        
        while (current)
        {
            if (current->value <= current->next->value)
			{

			}
			current = current->next;
        }
        // if (max_pos <= b_size / 2)
        // {
        //     while (max_pos > 0)
        //     {
        //         rotate(stack_b, 'b');
        //         max_pos--;
        //     }
        // }
        // else
        // {
        //     while (max_pos < b_size)
        //     {
        //         reverse_rotate(stack_b, 'b');
        //         max_pos++;
        //     }
        // }
        // push(stack_b, stack_a, 'a');
		
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

