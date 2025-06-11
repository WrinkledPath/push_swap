#include "push_swap.h"

int	is_sorted(Node *head)
{
	if (!head)
		return (1);
	while(head->next != NULL)
	{
		if (head->x > head->next->x)
			return (0);
		head = head->next;
	}
	return (1);
}
