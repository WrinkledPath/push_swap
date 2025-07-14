# Project name
NAME = push_swap

# Source files
SRC = main.c node_utils.c stack_utils.c small_sort.c print_sort_a.c print_sort_b.c turk_sort.c turk_assignment.c indexing.c
OBJ = $(SRC:.c=.o)

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
CFLAGS += -I/usr/lib/modules/6.11.11-valve20-1-neptune-611-gd35c3ed359a0/build/include/uapi \
          -I/usr/lib/modules/6.11.11-valve20-1-neptune-611-gd35c3ed359a0/build/include

# Paths to libraries and includes
LIBFT_DIR = ./local_includes/Libft

INCLUDES = -I. -I$(LIBFT_DIR)
LIBS = $(LIBFT_DIR)/libft.a

# Default target
all: $(NAME)

# Linking final executable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -I. $(OBJ) $(LIBS) -o $(NAME)

# Compiling object files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJ)

# Clean everything
fclean: clean
	rm -f $(NAME)

# Rebuild
re: fclean all


