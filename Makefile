CC = cc
CFLAGS = -g -Wall -Wextra -Werror
RM = rm -rf
NAME = push_swap
SRC_1 = src/push_swap.c
SRC_2 = src/command_lst.c \
		src/free.c \
		src/ft_split.c \
		src/functions.c \
		src/init.c \
		src/instructions.c \
		src/instructions_double.c \
		src/move_a_to_b.c \
		src/move_b_to_a.c \
		src/sort_list.c \

OBJ_1 = $(SRC_1:.c=.o)
OBJ_2 = $(SRC_2:.c=.o)


all: $(NAME)

$(NAME): $(OBJ_1) $(OBJ_2)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_1) $(OBJ_2)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_1) $(OBJ_2)

fclean: clean
	@$(RM) $(NAME)

re: fclean all