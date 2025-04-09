CC      = cc
CFLAGS  = -Wall -Wextra -Werror
SRC     = main.c parsing.c conversion.c list_utils.c string_utils.c ft_split.c \
          operations.c operations2.c sort.c sort_large.c
NAME    = push_swap
OBJ_DIR = obj/
OBJ     = $(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))
HEADERS = push_swap.h

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o: %.c $(HEADERS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re