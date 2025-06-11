#include "push_swap.h"

static void	set_target(Node *stack_a, Node *stack_b);
static void	set_price(Node *stack_a, Node *stack_b);
static Node *set_cheapest(Node *stack_b);

Node 	*turk_assignment(Node *stack_a, Node *stack_b)
{
	set_target(stack_a, stack_b);
	set_pos(stack_a, stack_b);
	set_medium(stack_a, stack_b);
	set_price(stack_a, stack_b);	
	return (set_cheapest(stack_b));
}

static void	set_target(Node *stack_a, Node *stack_b)
{
	Node *curr_a;
	Node *target;
	long	best_match;
	
	while (stack_b)
	{
		best_match = LONG_MAX;
		curr_a = stack_a;
		while (curr_a)
		{		
			if (curr_a->x > stack_b->x && curr_a->x < best_match)
			{
				best_match = curr_a->x;
				target = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (best_match == LONG_MAX)
			stack_b->target_node = find_min(stack_a);
		else
			stack_b->target_node = target;	
		stack_b = stack_b->next;
	}	
}

void	set_pos(Node *stack_a, Node *stack_b)
{
	int i;

	i = 0;
	while (stack_a)
	{
		stack_a->pos = i;
		stack_a = stack_a->next;
		i++;
	}
	i = 0;
	while (stack_b)
	{
		stack_b->pos = i;
		stack_b = stack_b->next;
		i++;
	}
}

void	set_medium(Node *stack_a, Node *stack_b)
{
	int len_a;
	int len_b;
	
	len_a = stack_len(stack_a);
	len_b = stack_len(stack_b);

	while (stack_a)
	{
		if (stack_a->pos <= (len_a / 2))
			stack_a->above_median = true;
		else 
			stack_a->above_median = false;
		stack_a = stack_a->next;
	}
	while (stack_b)
	{
		if (stack_b->pos <= (len_b / 2))
			stack_b->above_median = true;
		else
			stack_b->above_median = false;
		stack_b = stack_b->next;
	}
}

static void	set_price(Node *stack_a, Node *stack_b)
{
	int	len_a;
	int len_b;

	len_a = stack_len(stack_a);
	len_b = stack_len(stack_b);
	while (stack_b)
	{
		stack_b->push_price = stack_b->pos;
		if (!(stack_b->above_median))
			stack_b->push_price = len_b - (stack_b->pos);
		if (stack_b->target_node->above_median)
			stack_b->push_price += stack_b->target_node->pos;
		else
			stack_b->push_price += len_a - (stack_b->target_node->pos);
		stack_b = stack_b->next;
	}
}

static Node	*set_cheapest(Node *stack_b)
{
	Node *min;
	
	min = stack_b;
	while (stack_b)
	{
		if (stack_b->push_price < min->push_price)
			min = stack_b;
		stack_b = stack_b->next;
	}
	min->cheapest = true;
	return (min);
}
