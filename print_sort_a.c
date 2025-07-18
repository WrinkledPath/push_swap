/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sort_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywagner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:24:33 by ywagner           #+#    #+#             */
/*   Updated: 2025/07/15 13:49:45 by ywagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sa(t_list **root, bool print)
{
	if (print)
		write(1, "sa\n", 3);
	swap(root);
}

void	pa(t_list **stack_a, t_list **stack_b, bool print)
{
	if (print)
		write(1, "pa\n", 3);
	push_node(stack_b, stack_a);
}

void	ra(t_list **root, bool print)
{
	if (print)
		write(1, "ra\n", 3);
	rotate_list(root);
}

void	rra(t_list **root, bool print)
{
	if (print)
		write(1, "rra\n", 4);
	reverse_rotate(root);
}

void	rr(t_list **stack_a, t_list **stack_b, bool print)
{
	if (print)
		write(1, "rr\n", 3);
	rotate_list(stack_a);
	rotate_list(stack_b);
}
