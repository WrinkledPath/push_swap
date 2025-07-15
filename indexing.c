/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywagner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:23:59 by ywagner           #+#    #+#             */
/*   Updated: 2025/07/15 11:24:04 by ywagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static	t_list	*min_unindexed_node(t_list *root);

void	assign_index(t_list *root)
{
	t_list	*curr;
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

static t_list	*min_unindexed_node(t_list *root)
{
	t_list	*min;

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

t_list	*find_min(t_list *root)
{
	t_list	*min;

	min = root;
	while (root != NULL)
	{
		if (root->x < min->x)
			min = root;
		root = root->next;
	}
	return (min);
}

t_list	*find_max(t_list *root)
{
	t_list	*max;

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

t_list	*set_cheap(t_list *stack_b)
{
	t_list	*min;

	min = stack_b;
	while (stack_b)
	{
		if (stack_b->push_price < min->push_price)
			min = stack_b;
		if (stack_b->cheap)
			stack_b->cheap = false;
		stack_b = stack_b->next;
	}
	min->cheap = true;
	return (min);
}
