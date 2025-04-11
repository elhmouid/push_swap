/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hmo <moel-hmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 22:31:05 by moel-hmo          #+#    #+#             */
/*   Updated: 2025/04/11 22:32:03 by moel-hmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_list
{
	int				position;
	long			value;
	struct s_list	*next;
	int				index;
}	t_list;

int		ft_strlen(char *str);
void	ft_putstr_fd(char *str, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_error(char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		check_args(char *str);
int		basic_parsing(char **av);
int		empty_string(char *str);
int		ft_isdigit(int c);
int		ft_isspace(char c);
long	ft_atoi(char *str);
int		skip_whitespace_and_sign(char *str, int *sign);
long	process_number(char *digit_str, int sign);
int		is_duplicate(t_list *stack);
int		check_integers(t_list *stack);
t_list	*new_node(long value);
void	add_back(t_list **stack, t_list *node);
void	parse_args(char *arg, t_list **stack);
void	free_stack(t_list **stack);
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
void	sort_small(t_list **stack_a, t_list **stack_b, int size);
void	sort_two(t_list **stack);
void	sort_three(t_list **stack);
int		find_position(t_list *stack, long value);
void	move_min_to_top(t_list **stack_a);
void	sort_stack(t_list **stack_a, t_list **stack_b);
void	first_step(t_list **stack_a, t_list **stack_b);
void	index_stack(t_list *stack);
void	update_index(t_list *stack, int index);
void	assign_position(t_list *stack_b);
int		find_max_value(t_list *stack);
int		find_position_max(t_list *stack);
void	move_max_to_top(t_list **stack_b, int max_pos, int size);
void	push_back_to_a(t_list **stack_a, t_list **stack_b);
char	**ft_split(const char *s);

#endif