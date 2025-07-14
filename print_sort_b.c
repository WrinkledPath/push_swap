#include "push_swap.h"

void	pb(t_list **stack_a, t_list **stack_b)
{
	write(1, "pb\n", 3);
	push_node(stack_a, stack_b);
}

void	rb(t_list **root)
{
	write(1, "rb\n", 3);
	rotate_list(root);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	write(1, "rrr\n", 4);
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}

void	rrb(t_list **root)
{
	write(1, "rrb\n", 4);
	reverse_rotate(root);
}
