
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdbool.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

typedef struct Node {
	int	x;
	int index;
	int push_price;
	int pos;
	bool cheapest;
	bool above_median;
	struct Node *target_node;
	struct Node *next;
	struct Node *prev;
} Node;

// Linked List Moves
int		stack_len(Node *curr);
int		is_sorted(Node *head);
void	append_node(Node **head, int value);
void	rotate_list(Node **head);
void	reverse_rotate(Node **head);
void	push_node(Node **stack_a, Node **stack_b);
void	free_list(Node **head);
void	init_stack_a(Node **head, char **argv);
void	swap(Node **root);
Node	*find_last(Node *stack);
Node	*create_node(int value);

// Radix Sort
int		get_node_position(Node *stack, Node *target);
void	assign_index(Node *root);
void	sort_pipe(Node **stack_a, Node **stack_b);
void	radix_sort(Node **stack_a, Node **stack_b);
void	tiny_sort(Node **root);
Node	*find_min(Node *root);
Node	*find_max(Node *root);

// Turk Sort
Node 	*turk_assignment(Node *stack_a, Node *stack_b);
void	turk_sort(Node **stack_a, Node **stack_b);
void	set_medium(Node *stack_a, Node *stack_b);
void	set_pos(Node *stack_a, Node *stack_b);

// Print Functions
void	sa(Node **root);
void	ra(Node **root);
void	rra(Node **root);
void	rb(Node **root);
void	rrb(Node **root);
void	rr(Node **stack_a, Node **stack_b);
void	rrr(Node **stack_a, Node **stack_b);
void	pa(Node **stack_a, Node **stack_b);
void	pb(Node **stack_a, Node **stack_b);

// Testing Functions
int		validate_index_range(Node *stack);
void	print_pipe(Node *stack_a, Node *stack_b);
void	print_small(Node *stack_a, Node *stack_b);
void	print_both(Node *stack_a, Node *stack_b);

#endif
