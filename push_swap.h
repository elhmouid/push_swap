#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

// Stack node structure
typedef struct s_list
{
	int				position;
	long			value;
	struct s_list	*next;
	int				index;
}	t_list;

// Conversion functions
long	ft_atoi(char *str);
int		is_duplicate(t_list *stack);
int		check_integers(t_list *stack);
int		skip_whitespace(char *str);
int		handle_sign(char *str, int *i);
long	convert_to_long(char *str, int i, int sign);

// String utilities
char	**ft_split(const char *s);
int		ft_strlen(char *str);
void	ft_putstr_fd(char *str, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_error(char *str);

// List operations
t_list	*new_node(long value);
void	add_back(t_list **stack, t_list *node);
void	parse_args(char *arg, t_list **stack);
void	free_stack(t_list **stack);

// Parsing functions
int		check_args(char *str);void print_stack(t_list *stack);
// Stack operations
void	swap(t_list **stack, char stack_name);
void	swap_both(t_list **stack_a, t_list **stack_b);
void	push(t_list **src, t_list **dst, char dst_name);
void	rotate(t_list **stack, char stack_name);
void	rotate_both(t_list **stack_a, t_list **stack_b);
void	reverse_rotate(t_list **stack, char stack_name);
void	reverse_rotate_both(t_list **stack_a, t_list **stack_b);
int		stack_size(t_list *stack);
int		is_sorted(t_list *stack);
t_list	*find_min(t_list *stack);

// Sorting functions
void	sort_stack(t_list **stack_a, t_list **stack_b);
void	sort_small(t_list **stack_a, t_list **stack_b, int size);
void	sort_two(t_list **stack);
void	sort_three(t_list **stack);
void	sort_large(t_list **stack_a, t_list **stack_b);
int		find_position(t_list *stack, long value);
void	move_min_to_top(t_list **stack_a);
void	get_three_values(t_list *stack, int *first, int *second, int *third);

// New chunking sort functions
long	*create_sorted_array(t_list *stack, int size);
void	sort_array(long *arr, int size);
void 	index_stack(t_list *stack);
int		get_chunk_size(int size);
int	basic_parsing(char **av);
int	empty_string(char *str);
int ft_isspace(char c);
int	ft_isdigit(int c);

int		find_next_in_chunk(t_list *stack, int chunk_start, int chunk_end);
int		get_efficient_direction(t_list *stack, int chunk_start, int chunk_end);
void	push_chunks_to_b(t_list **stack_a, t_list **stack_b, int size);
void	move_to_top(t_list **stack, int chunk_start, int chunk_end, int direction);
void	push_back_to_a(t_list **stack_a, t_list **stack_b);
long	find_max_value(t_list *stack);


void print_stack(t_list *stack);

void first_step(t_list **stack_a, t_list **stack_b);


#endif