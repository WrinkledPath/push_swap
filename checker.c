#include "checker.h"

static void	exit_free(t_list **a, t_list **b, char **args, bool err);
static void	exec_inst(char *line, t_list **a, t_list **b);
static void	read_exec(t_list **a, t_list **b);
static char	find_delim(char *str);

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	delim;
	char	**args;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	else if (argc == 2)
	{
		delim = find_delim(argv[1]);
		args = ft_split(argv[1], delim);
	}
	else
		args = argv + 1;
	if ((init_stack_a(&a, args)) == -1)
		exit_free(&a, &b, args, 1);
	read_exec(&a, &b);
	if (is_sorted(a) && stack_len(b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	exit_free(&a, &b, args, 0);
	return (0);
}

static char	find_delim(char *str)
{
	int	i;

	if (!str)
		return (' ');
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			return (str[i]);
		i++;
	}
	return (' ');
}

static void	exit_free(t_list **a, t_list **b, char **args, bool err)
{
	if (a)
		free_list(a);
	if (b)
		free_list(b);
	if (args)
	{
		while (*args)
		{
			free(*args);
			args++;
		}
		free(args);
	}
	if (err == 1)
		write(1, "Error\n", 6);
	exit(1);
}

static void	exec_inst(char *line, t_list **a, t_list **b)
{
	if (!ft_strcmp(line, "pa"))
		pa(a, b);
	else if (!ft_strcmp(line, "pb"))
		pb(a, b);
	else if (!ft_strcmp(line, "ra"))
		ra(a);
	else if (!ft_strcmp(line, "rb"))
		rb(b);
	else if (!ft_strcmp(line, "rr"))
		rr(a, b);
	else if (!ft_strcmp(line, "rra"))
		rra(a);
	else if (!ft_strcmp(line, "rrb"))
		rrb(b);
	else if (!ft_strcmp(line, "rrr"))
		rrr(a, b);
	else
		exit_free(a, b, NULL, 1);
}

static void	read_exec(t_list **a, t_list **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (ft_strlen(line) > 0 &&
			line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = 0;
		exec_inst(line, a, b);
		free(line);
		line = get_next_line(0);
	}
}
