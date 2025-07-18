NAME = get_next_line.a
CC = gcc
FLAGS = -Wall -Werror -Wextra
CFLAGS += -I/usr/lib/modules/6.11.11-valve20-1-neptune-611-gd35c3ed359a0/build/include/uapi \
          -I/usr/lib/modules/6.11.11-valve20-1-neptune-611-gd35c3ed359a0/build/include
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
