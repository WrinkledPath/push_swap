#include "push_swap.h"

static int		error_syntax(char *argv);
static int		error_duplicates(Node *head, int value);

void	init_stack_a(Node **head, char **argv)
{
	int		i;
	long	n;

	if (!head || (!*head && !argv[1]))
			return ;
	i = 0;
	while (argv[i] != NULL)
	{
		n = ft_atol(argv[i]);
		if (error_syntax(argv[i]))
		{
			ft_printf("Non-Numeric Char Error\n");
			free_list(head);
			return ;
		}
		else if (n > INT_MAX || n < INT_MIN)
		{
			ft_printf("Bigger/Smaller than Max\n");
			free_list(head);
			return ;
		}
		else if (error_duplicates(*head, (int)n))
		{
			ft_printf("Duplicate Numbers\n");
			free_list(head);
			return ;
		}
		else
			append_node(head, (int)n);
		i++;
	}
}

static int		error_duplicates(Node *head, int value)
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

static int		error_syntax(char *argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
		if ((argv[i] < '0' || argv[i] > '9') && argv[i] != '+' && argv[i] != '-' && argv[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int		stack_len(Node *curr)
{
	int	up;
	int	down;
	Node *p_prev;

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

