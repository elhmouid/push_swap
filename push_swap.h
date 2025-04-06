#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
# include <stdlib.h>

void	ft_error(char *str);
void	ft_putstr_fd(char *str, int fd);
void    ft_putchar_fd(char c, int fd);


int		ft_atoi(char *str);
int		ft_isdigit(int c);
int	basic_parsing(int ac, char **av);

char	**ft_split(char const *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}	t_list;

void add_back(t_list **stack, t_list *node);
t_list	*new_node(int value);
void	parse_args(char *arg, t_list **stack);



# endif
