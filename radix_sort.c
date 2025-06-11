#include "push_swap.h"

static int	calculate_loops(Node *stack_a);
static void	radix_actions(Node **stack_a, Node **stack_b, int i);

void	radix_sort(Node **stack_a, Node **stack_b)
{
	int	n_loops;
	int i;
	Node *max;

	max = find_max(*stack_a);
	print_small(*stack_a, *stack_b);
	n_loops = calculate_loops(max);
	i = 0;
	while (i < n_loops && !is_sorted(*stack_a))
	{
		radix_actions(stack_a, stack_b, i);
		while (*stack_b)
		{
			pa(stack_a, stack_b);
			print_small(*stack_a, *stack_b);
		}
		i++;
	}
}

static void	radix_actions(Node **stack_a, Node **stack_b, int i)
{
	int	s_len;
	int n;

	s_len = stack_len(*stack_a);
	n = 0;
	while (n < s_len && !is_sorted(*stack_a))
	{
		if (((*stack_a)->index >> i) & 1)
			ra(stack_a);
		else
			pb(stack_a, stack_b);
		n++;
		print_small(*stack_a, *stack_b);
	}
}

static int	calculate_loops(Node *stack_a)
{
	int i;

	if (!stack_a)
		return (0);
	i = 0;
	while ((stack_a->index >> i) != 0)
		i++;
	return (i);
}

