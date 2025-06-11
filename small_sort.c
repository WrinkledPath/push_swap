#include "push_swap.h"

static void	small_sort(Node **stack_a, Node **stack_b);
static void	rotate_tiny_sort(Node **stack_a);

void	sort_pipe(Node **stack_a, Node **stack_b)
{
	int		n;

	if (!stack_a)
		return ;
	if (is_sorted(*stack_a))
		return ;
	n = stack_len(*stack_a);
	if (n == 3)
		tiny_sort(stack_a);
	else if (n <= 5)
		small_sort(stack_a, stack_b);
	else
		turk_sort(stack_a, stack_b);
}

void	tiny_sort(Node **root)
{
	Node *max;

	max = find_max(*root);
	if (max->prev == NULL)
		ra(root);
	else if (max->next != NULL)
		rra(root);
	if ((*root)->x > (*root)->next->x)
		sa(root);
}

static void	small_sort(Node **stack_a, Node **stack_b)
{
	int	s_len;
	int	times;
	int	i;

	if (!stack_a || !*stack_a)
		return ;
	s_len = stack_len(*stack_a);
	if (s_len == 5)
		times = 2;
	else 
		times = 1;
	i = 0;
	while (i++ < times)
	{
		rotate_tiny_sort(stack_a);
		pb(stack_a, stack_b);
	}
	tiny_sort(stack_a);
	i = 0;
	while (i++ < times)
		pa(stack_a, stack_b);
}

static void	rotate_tiny_sort(Node **stack_a)
{
	int	s_len;
	int	p_min;
	Node *min;

	s_len = stack_len(*stack_a);
	min = find_min(*stack_a);
	p_min = get_node_position(*stack_a, min);
	if (p_min <= s_len / 2)
	{
		while (*stack_a != min)
			ra(stack_a);
	}
	else
	{
		while (*stack_a != min)
			rra(stack_a);
	}
}

int		get_node_position(Node *stack, Node *target)
{
	int i;

	if (!stack)
		return (-1);
	i = 0;
	while (stack != target)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

Node *find_min(Node *root)
{
	Node *min;

	min = root;
	while (root != NULL)
	{
		if (root->x < min->x)
			min = root;
		root = root->next;
	}
	return (min);
}

Node	*find_max(Node *root)
{
	Node	*max;

	if (!root)
		return (NULL);
	max = root;
	while (root != NULL)
	{
		if (root->x > max->x)
			max = root;
		root = root->next;
	}
	return (max);
}

