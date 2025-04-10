#include "push_swap.h"

// void set_index(t_list *stack, int index, int min)
// {
//     t_list *tmp;

//     tmp = stack;
//     while (tmp)
//     {
//         if (tmp->value == min)
//             tmp->index = index;
//         tmp = tmp->next;
//     }
// }


void index_stack(t_list *stack)
{
    int s = stack_size(stack);
    int index = 0;
    t_list *tmp = stack;
    t_list *tr = NULL;

    while (s)
    {
        int min = INT_MAX;

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
        else if ((*stack_a)->index <= i + 15) {
            push(stack_a, stack_b, 'b');
            rotate(stack_b, 'b');
            i++;
        }
        else {
            rotate(stack_a, 'a');
        }
        size--;
    }
    print_stack(*stack_b);
}


void print_stack(t_list *stack)
{
    t_list *current = stack;
    
    while (current)
    {
        printf("Value: %ld, Index: %d\n", current->value, current->index);
        current = current->next;
    }
}

