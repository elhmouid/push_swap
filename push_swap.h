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

char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

typedef struct s_list
{
    int     *arr;
    char    **array;
} t_list;


# endif
