#include "push_swap.h"

static	Node	*min_unindexed_node(Node *root);

void	assign_index(Node *root)
{
	Node	*curr;
	int		i;
	int		j;

	i = 0;
	j = stack_len(root);
	while (i < j)
	{
		curr = min_unindexed_node(root);		
		curr->index = i;
		i++;
	}
}

static Node	*min_unindexed_node(Node *root)
{
	Node	*min;

	if (!root)
		return (NULL);
	while (root->index != -1)
		root = root->next;
	min = root;
	while (root)
	{
		if (root->index == -1 && root->x < min->x)
			min = root;
		root = root->next;
	}
	return (min);
}


