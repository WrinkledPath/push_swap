#include "push_swap.h"

int	main(int argc, char **argv)
{
	Node *stack_a;
	Node *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (-1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv += 1;
	init_stack_a(&stack_a, argv);
	assign_index(stack_a);
	sort_pipe(&stack_a, &stack_b);
	return (0);
}
