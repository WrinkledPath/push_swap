/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywagner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:32:03 by ywagner           #+#    #+#             */
/*   Updated: 2025/07/19 18:33:12 by ywagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	free_split(char **args);

int	handle_args(t_list **stack_a, char **argv, int argc)
{
	char	**args;

	if (!stack_a || !argv || !*argv)
		return (-1);
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args || init_stack_a(stack_a, args) == -1)
		{
			free_split(args);
			write(2, "Error\n", 6);
			return (-1);
		}
		free_split(args);
	}
	else
	{
		if (init_stack_a(stack_a, argv + 1) == -1)
		{
			write(2, "Error\n", 6);
			return (-1);
		}
	}
	return (0);
}

static void	free_split(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}
