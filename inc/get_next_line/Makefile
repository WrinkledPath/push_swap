NAME = get_next_line.a
CC = gcc
FLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f

SRC = get_next_line.c get_next_line_utils.c
OBJ = $(SRC:%.c=%.o)

all:$(NAME)

%.o: %.c get_next_line.h Makefile
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re
