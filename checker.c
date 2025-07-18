#include "checker.h"

static void	exec_inst(char *line, t_list **a, t_list **b);
static void	read_exec(t_list **a, t_list **b);

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
	read_exec(&a, &b);
	if (is_sorted(a) && stack_len(b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_list(&a);
	free_list(&b);
	return (0);
}

static void	exec_inst(char *line, t_list **a, t_list **b)
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
		free_list(b);
		write(2, "Error\n", 6);
		exit(1);
	}
}

static void	read_exec(t_list **a, t_list **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (ft_strlen(line) > 0
			&& line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = 0;
		exec_inst(line, a, b);
		free(line);
		line = get_next_line(0);
	}
}
