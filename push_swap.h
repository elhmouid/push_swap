#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
# include <stdlib.h>

typedef struct s_list
{
	long			value;
	struct s_list	*next;
}	t_list;

long		ft_atoi(char *str);
int	is_duplicate(t_list *stack);
int check_integers(t_list *stack);

char	**ft_split(char const *s);

t_list	*new_node(long value);
void add_back(t_list **stack, t_list *node);
void	parse_args(char *arg, t_list **stack);

int check_args(char *str);
int	basic_parsing(int ac, char **av);
int	empty_string(char *str);
int		ft_isdigit(int c);
int ft_isspace(char c);



void	ft_error(char *str);
void	ft_putstr_fd(char *str, int fd);
void    ft_putchar_fd(char c, int fd);



size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);





int	ft_strlen(char *str);

// int	check_len(t_list *stack);

# endif
