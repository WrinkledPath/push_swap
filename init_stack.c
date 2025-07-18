/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywagner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:24:09 by ywagner           #+#    #+#             */
/*   Updated: 2025/07/15 17:59:56 by ywagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int		error_syntax(char *argv);
static int		error_duplicates(t_list *head, int value);

int	init_stack_a(t_list **head, char **argv)
{
	int		i;
	long	n;

	if (!argv && !*argv)
		return (-1);
	i = 0;
	while (argv[i] != NULL)
	{
		n = ft_atol(argv[i]);
		if (error_syntax(argv[i]))
			return (free_list(head));
		else if (n > INT_MAX || n < INT_MIN)
			return (free_list(head));
		else if (error_duplicates(*head, (int)n))
			return (free_list(head));
		else if ((append_node(head, (int)n) == -1))
			return (free_list(head));
		i++;
	}
	return (0);
}

static int	error_duplicates(t_list *head, int value)
{
	t_list	*curr;

	curr = head;
	if (!head)
		return (0);
	while (curr)
	{
		if (curr->x == value)
			return (1);
		curr = curr->next;
	}
	return (0);
}

static int	error_syntax(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if ((argv[i] < '0' || argv[i] > '9')
			&& argv[i] != '+'
			&& argv[i] != '-'
			&& argv[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	stack_len(t_list *curr)
{
	int		up;
	int		down;
	t_list	*p_prev;

	if (!curr)
		return (0);
	up = 0;
	down = 0;
	p_prev = curr->prev;
	while (p_prev)
	{
		p_prev = p_prev->prev;
		up++;
	}
	while (curr)
	{
		down++;
		curr = curr->next;
	}
	return (up + down);
}
