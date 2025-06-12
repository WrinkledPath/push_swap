#include "push_swap.h"

static void	rotate_big_sort(Node **stack_a, Node **stack_b, Node *cheapest);
static int	same_direction(Node *stack_b);
static int	calculate_rotations(Node *root);
static void	final_rotations(Node **stack_a, Node **stack_b, Node *cheapest);

void	turk_sort(Node **stack_a, Node **stack_b)
{
	Node *smallest;
	Node *cheapest;
	
	while (stack_len(*stack_a) > 3)
	{
		if ((*stack_a)->index > (stack_len(*stack_a) / 2))
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	tiny_sort(stack_a);
	while (*stack_b)
	{
		cheapest = turk_assignment(*stack_a, *stack_b);
		rotate_big_sort(stack_a, stack_b, cheapest);	
		pa(stack_a, stack_b);
	}
	set_pos(*stack_a, *stack_b);	
	set_medium(*stack_a, *stack_b);	
	smallest = find_min(*stack_a);
	if (smallest->above_median)
		while (*stack_a != smallest)
			ra(stack_a);
	else
		while (*stack_a != smallest)
			rra(stack_a);
}

static void	rotate_big_sort(Node **stack_a, Node **stack_b, Node *cheapest)
{
	int	a_rot;
	int	b_rot;

	a_rot = calculate_rotations(cheapest->target_node);
	b_rot = calculate_rotations(cheapest);
	while (a_rot != 0 && b_rot != 0 && same_direction(cheapest))
	{
		if (cheapest->above_median)
			rr(stack_a, stack_b);
		else
			rrr(stack_a, stack_b);
		a_rot--;
		b_rot--;
	}
	final_rotations(stack_a, stack_b, cheapest);
}

static void	final_rotations(Node **stack_a, Node **stack_b, Node *cheapest)
{
	while (*stack_b != cheapest)
	{
		if (cheapest->above_median)
			rb(stack_b);
		else
			rrb(stack_b);
	}
	while (*stack_a != cheapest->target_node)
	{
		if (cheapest->target_node->above_median)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

static int	calculate_rotations(Node *root)
{
	int	rotations;

	rotations = 0;
	if (root->above_median)
		rotations = root->pos;
	else
		rotations = stack_len(root) - root->pos;
	return (rotations);
}

static int	same_direction(Node *node)
{
	return (node->above_median == node->target_node->above_median);
}
