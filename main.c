#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	i;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (-1);
	else if (argc == 2)
	{
		i = 0;
		while (argv[1][i] != ' ' && argv[1][i] != '\n')
			i++;
		argv = ft_split(argv[1], argv[1][i]);
	}
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
