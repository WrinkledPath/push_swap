#include "push_swap.h"

void	rotate_list(t_list **head)
{
	t_list	*aux;
	t_list	*tail;

	if (!head || !*head || !(*head)->next)
		return ;
	tail = *head;
	while (tail->next != NULL)
		tail = tail->next;
	aux = *head;
	(*head)->next->prev = NULL;
	*head = (*head)->next;
	aux->next = NULL;
	aux->prev = tail;
	tail->next = aux;
}

void	reverse_rotate(t_list **head)
{
	t_list	*aux;
	t_list	*tail;

	if (!head || !*head || !(*head)->next)
		return ;
	tail = find_last(*head);
	aux = tail;
	tail->prev->next = NULL;
	tail = tail->prev;
	aux->prev = NULL;
	aux->next = *head;
	(*head)->prev = aux;
	*head = aux;
}

int	free_list(t_list **head)
{
	t_list	*curr;
	t_list	*next;

	if (!head || !*head)
		return ;
	curr = *head;
	while (curr != NULL)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	*head = NULL;
	return (-1);
}

void	swap(t_list **root)
{
	t_list	*aux;

	if (!root || !*root)
		return ;
	aux = (*root)->next;
	aux->next->prev = *root;
	aux->prev = NULL;
	(*root)->next = aux->next;
	aux->next = *root;
	(*root)->prev = aux;
	*root = aux;
}

int	is_sorted(t_list *head)
{
	if (!head)
		return (1);
	while (head->next != NULL)
	{
		if (head->x > head->next->x)
			return (0);
		head = head->next;
	}
	return (1);
}
