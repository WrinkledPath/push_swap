/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywagner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:26:06 by ywagner           #+#    #+#             */
/*   Updated: 2025/07/15 13:27:27 by ywagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	calculate_rotations(t_list *root);
static void	rotate_big_sort(t_list **stack_a, t_list **stack_b, t_list *cheap);
static void	final_rotations(t_list **stack_a, t_list **stack_b, t_list *cheap);
static void	rotate_rest(t_list **stack_a);

void	turk_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheap;

	while (stack_len(*stack_a) > 3)
	{
		if ((*stack_a)->index > (stack_len(*stack_a) / 2))
			pb(stack_a, stack_b, true);
		else
			ra(stack_a, true);
	}
	tiny_sort(stack_a);
	while (*stack_b)
	{
		cheap = turk_assignment(*stack_a, *stack_b);
		rotate_big_sort(stack_a, stack_b, cheap);
		pa(stack_a, stack_b, true);
	}
	set_pos(*stack_a, *stack_b);
	set_medium(*stack_a, *stack_b);
	rotate_rest(stack_a);
}

static void	rotate_rest(t_list **stack_a)
{
	t_list	*smallest;

	smallest = find_min(*stack_a);
	if (smallest->above_median)
		while (*stack_a != smallest)
			ra(stack_a, true);
	else
		while (*stack_a != smallest)
			rra(stack_a, true);
}

static void	rotate_big_sort(t_list **stack_a, t_list **stack_b, t_list *cheap)
{
	int	a_rot;
	int	b_rot;

	a_rot = calculate_rotations(cheap->target_node);
	b_rot = calculate_rotations(cheap);
	while (a_rot != 0 && b_rot != 0 && same_direction(cheap))
	{
		if (cheap->above_median)
			rr(stack_a, stack_b, true);
		else
			rrr(stack_a, stack_b, true);
		a_rot--;
		b_rot--;
	}
	final_rotations(stack_a, stack_b, cheap);
}

static void	final_rotations(t_list **stack_a, t_list **stack_b, t_list *cheap)
{
	while (*stack_b != cheap)
	{
		if (cheap->above_median)
			rb(stack_b, true);
		else
			rrb(stack_b, true);
	}
	while (*stack_a != cheap->target_node)
	{
		if (cheap->target_node->above_median)
			ra(stack_a, true);
		else
			rra(stack_a, true);
	}
}

static int	calculate_rotations(t_list *root)
{
	int	rotations;

	rotations = 0;
	if (root->above_median)
		rotations = root->pos;
	else
		rotations = stack_len(root) - root->pos;
	return (rotations);
}
