# Project name
NAME = push_swap

# Source files
SRC = main.c node_utils.c stack_utils.c push_swap.c testing_code.c init_node.c radix_sort.c small_sort.c rad_indexing.c print_sort.c turk_sort.c turk_assignment.c
OBJ = $(SRC:.c=.o)

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
CFLAGS += -I/usr/lib/modules/6.1.52-valve16-1-neptune-61/build/include/uapi \
          -I/usr/lib/modules/6.1.52-valve16-1-neptune-61/build/include

# Paths to libraries and includes
LIBFT_DIR = ./local_includes/Libft
PRINTF_DIR = ./local_includes/ft_printf

INCLUDES = -I. -I$(LIBFT_DIR) -I$(PRINTF_DIR)
LIBS = $(LIBFT_DIR)/libft.a $(PRINTF_DIR)/ft_printf.a

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


