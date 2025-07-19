/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywagner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:32:43 by ywagner           #+#    #+#             */
/*   Updated: 2025/07/19 17:32:46 by ywagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (-1);
	if (handle_args(&stack_a, argv, argc) == -1)
		return (-2);
	assign_index(stack_a);
	sort_pipe(&stack_a, &stack_b);
	free_list(&stack_a);
	free_list(&stack_b);
	return (0);
}
