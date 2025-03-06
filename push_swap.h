#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
void	fail_error(char *str);
void	ft_putstr_fd(char *str, int fd);
void    ft_putchar_fd(char c, int fd);


int		ft_atoi(char *str);
char	**ft_split(int ac, char **av);
int		ft_isdigit(int c);
void	parsing(char **av);



# endif
