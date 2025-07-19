# Compiler and flags
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -Iinc/Libft -Iinc/get_next_line -I.

# Source files
SRCS        = init_stack.c indexing.c node_utils.c stack_utils.c \
              small_sort.c turk_sort.c turk_assignment.c print_sort_a.c \
              print_sort_b.c parse_args.c

OBJS        = $(SRCS:.c=.o)

# Unique source files
PUSH_SRC    = main.c
PUSH_OBJ    = $(PUSH_SRC:.c=.o)
BONUS_SRC   = checker.c
BONUS_OBJ   = $(BONUS_SRC:.c=.o)

NAME        = push_swap
BONUS_NAME  = checker

# Libraries
LIBFT_DIR   = inc/Libft
GNL_DIR     = inc/get_next_line
LIBFT       = $(LIBFT_DIR)/libft.a
GNL         = $(GNL_DIR)/get_next_line.a

# Default rule
all: $(LIBFT) $(GNL) clean_bonus $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(GNL):
	$(MAKE) -C $(GNL_DIR)

$(NAME): $(OBJS) $(PUSH_OBJ)
	$(CC) $(CFLAGS) $^ $(LIBFT) $(GNL) -o $(NAME)

bonus: $(LIBFT) $(GNL) $(OBJS) $(BONUS_OBJ) $(NAME)
	$(CC) $(CFLAGS) $(OBJS) $(BONUS_OBJ) $(LIBFT) $(GNL) -o $(BONUS_NAME)

clean_bonus:
	rm -f $(BONUS_NAME) $(BONUS_OBJ)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(GNL_DIR)
	rm -f $(OBJS) $(PUSH_OBJ)

fclean: clean clean_bonus
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(GNL_DIR)
	rm -f $(NAME)

re: fclean all

