/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywagner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:34:25 by ywagner           #+#    #+#             */
/*   Updated: 2025/07/19 19:01:04 by ywagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

static int	exec_inst(char *line, t_list **a, t_list **b);
static int	read_exec(t_list **a, t_list **b);
static int	gnl_drain(int fd);

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (-1);
	if (handle_args(&a, argv, argc) == -1)
		return (-2);
	if (read_exec(&a, &b) == -1)
		return (gnl_drain(0));
	if (is_sorted(a) && stack_len(b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_list(&a);
	free_list(&b);
	return (0);
}

static int	exec_inst(char *line, t_list **a, t_list **b)
{
	if (!ft_strcmp(line, "sa"))
		sa(a, false);
	else if (!ft_strcmp(line, "pa"))
		pa(a, b, false);
	else if (!ft_strcmp(line, "pb"))
		pb(a, b, false);
	else if (!ft_strcmp(line, "ra"))
		ra(a, false);
	else if (!ft_strcmp(line, "rb"))
		rb(b, false);
	else if (!ft_strcmp(line, "rr"))
		rr(a, b, false);
	else if (!ft_strcmp(line, "rra"))
		rra(a, false);
	else if (!ft_strcmp(line, "rrb"))
		rrb(b, false);
	else if (!ft_strcmp(line, "rrr"))
		rrr(a, b, false);
	else
	{
		free_list(a);
		write(2, "Error\n", 6);
		return (free_list(b));
	}
	return (0);
}

static int	read_exec(t_list **a, t_list **b)
{
	char	*line;
	int		size;

	line = get_next_line(0);
	size = 0;
	while (line)
	{
		size = ft_strlen(line);
		if (size > 0 && line[size - 1] == '\n')
			line[size - 1] = 0;
		if (exec_inst(line, a, b) == -1)
		{
			free(line);
			return (-1);
		}
		free(line);
		line = get_next_line(0);
	}
	return (0);
}

static int	gnl_drain(int fd)
{
	char	*drain;

	drain = get_next_line(fd);
	while (drain)
	{
		free(drain);
		drain = get_next_line(fd);
	}
	return (-1);
}
