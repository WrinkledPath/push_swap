#include "push_swap.h"

int	append_node(t_list **stack, int value)
{
	t_list	*new_node;
	t_list	*last;

	if (!stack)
		return (-1);
	new_node = create_node(value);
	if (!new_node)
		return (-1);
	if (*stack == NULL)
	{
		*stack = new_node;
		return (0);
	}
	last = find_last(*stack);
	new_node->prev = last;
	last->next = new_node;
	return (0);
}

t_list	*find_last(t_list *stack)
{
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	push_node(t_list **stack_a, t_list **stack_b)
{
	t_list	*aux;

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

t_list	*create_node(int value)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->x = value;
	new_node->index = -1;
	new_node->push_price = -1;
	new_node->cheap = false;
	new_node->above_median = false;
	new_node->target_node = NULL;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

int	same_direction(t_list *node)
{
	return (node->above_median == node->target_node->above_median);
}
