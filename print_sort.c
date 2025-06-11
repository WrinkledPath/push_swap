#include "push_swap.h"

void	sa(Node **root)
{
	write(1, "sa\n", 3);
	swap(root);
}

void	pa(Node **stack_a, Node **stack_b)
{
	write(1, "pa\n", 3);
	push_node(stack_b, stack_a);
}

void	pb(Node **stack_a, Node **stack_b)
{
	write(1, "pb\n", 3);
	push_node(stack_a, stack_b);
}

void	rra(Node **root)
{
	write(1, "rra\n", 4);
	reverse_rotate(root);
}

void	ra(Node **root)
{
	write(1, "ra\n", 3);
	rotate_list(root);
}

void	rb(Node **root)
{
	write(1, "rb\n", 3);
	rotate_list(root);
}

void	rr(Node **stack_a, Node **stack_b)
{
	write(1, "rr\n", 3);
	rotate_list(stack_a);
	rotate_list(stack_b);
}

void	rrr(Node **stack_a, Node **stack_b)
{
	write(1, "rrr\n", 4);
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}

void	rrb(Node **root)
{
	write(1, "rrb\n", 4);
	reverse_rotate(root);
}
