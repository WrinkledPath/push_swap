#include "push_swap.h"

static int		error_syntax(char *argv);
static int		error_duplicates(t_list *head, int value);

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (-1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv += 1;
	if ((init_stack_a(&stack_a, argv)) == -1)
		return (-2);
	assign_index(stack_a);
	sort_pipe(&stack_a, &stack_b);
	free_list(&stack_a);
	free_list(&stack_b);
	return (0);
}

int	init_stack_a(t_list **head, char **argv)
{
	int		i;
	long	n;

	if (!head || (!*head && !argv[1]))
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
	while (head != NULL)
	{
		if (head->x == value)
			return (1);
		if (head->next != NULL)
			head = head->next;
		else
			return (0);
	}
	return (0);
}

static int	error_syntax(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] < '0' || argv[i] > '9')
			return (1);
		else if (argv[i] != '+' && argv[i] != '-' && argv[i] != ' ')
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

	up = 0;
	down = 0;
	if (curr)
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
