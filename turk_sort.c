#include "push_swap.h"

static void	rotate_big_sort(Node **stack_a, Node **stack_b, Node *cheapest);
static int	same_direction(Node *stack_b);

void	turk_sort(Node **stack_a, Node **stack_b)
{
	Node *smallest;
	Node *cheapest;
	
	while (stack_len(*stack_a) > 3)
	{
		pb(stack_a, stack_b);
		if (stack_len(*stack_b) > 1 && (*stack_b)->x < (*stack_b)->next->x)
			rb(stack_b);
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
	while (*stack_a != cheapest->target_node || *stack_b != cheapest)
	{
		if (*stack_a != cheapest->target_node && *stack_b != cheapest && same_direction(cheapest))
		{
			if (cheapest->above_median)
				rr(stack_a, stack_b);
			else
				rrr(stack_a, stack_b);
		}
		else if (*stack_b != cheapest)
		{
			if (cheapest->above_median)
				rb(stack_b);
			else
				rrb(stack_b);
		}
		else
		{
			if (cheapest->target_node->above_median)
				ra(stack_a);
			else
				rra(stack_a);
		}
	}	
}

static int	same_direction(Node *node)
{
	return (node->above_median == node->target_node->above_median);
}
