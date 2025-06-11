#include "push_swap.h"

void	rotate_list(Node **head)
{
	Node *aux;
	Node *tail;

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

void	reverse_rotate(Node **head)
{
	Node *aux;
	Node *tail;

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

void	free_list(Node **head)
{
	Node *curr;
	Node *next;

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
}

void	swap(Node **root)
{
	Node	*aux;

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
