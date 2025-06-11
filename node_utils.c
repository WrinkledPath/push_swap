#include "push_swap.h"

void	append_node(Node **stack, int value)
{
	Node *new_node;
	Node *last;
	
	if (!stack)
		return ;
	new_node = create_node(value);
	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	last = find_last(*stack);
	new_node->prev = last;
	last->next = new_node;
}

Node	*find_last(Node *stack)
{
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	push_node(Node **stack_a, Node **stack_b)
{
	Node *aux;

	if (*stack_a == NULL)
		return ;
	aux = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	if (*stack_b)
	{
		aux->next = *stack_b;
		(*stack_b)->prev = aux;
	}
	else
		aux->next = NULL;
	aux->prev = NULL;
	*stack_b = aux;
}

Node	*create_node(int value)
{
	Node *new_node;

	new_node = malloc(sizeof(Node));
	if (new_node == NULL)
		return (NULL);
	new_node->x = value;
	new_node->index = -1;
	new_node->push_price = -1;
	new_node->cheapest = false;
	new_node->above_median = false;
	new_node->target_node = NULL;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

