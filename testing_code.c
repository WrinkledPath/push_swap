#include "push_swap.h"

static void print_stack(Node *stack);
static void	pb_node(Node *stack_a, Node *stack_b, int nn);
static void	print_line_int(int value_a, int value_b, char *str);
static int	digit_amount(int i);

void	print_pipe(Node *stack_a, Node *stack_b)
{
	if (stack_a && !stack_b)
	{
		printf("[Printing Stack_A]\n");
		print_stack(stack_a);
	}
	else if (!stack_a && stack_b)
	{
		printf("[Printing Stack_B]\n");
		print_stack(stack_b);
	}
	else if (stack_a && stack_b)
	{
		printf("[Printing Both Stacks]\n");
		print_both(stack_a, stack_b);
	}
	else 
		printf("No Stacks to Print");
}	

static void print_stack(Node *stack)
{
	int i;

	i = 1;
	while (stack != NULL)
	{		
		printf("--------------------------------------\n");
		if (stack->prev == NULL)
			printf("[HEAD]\n");
		printf("Node %i is : %i\n", i, stack->x);
	
		printf("  Prev : ");
		if (stack->prev != NULL)
			printf("%i\n", stack->prev->x);
		else
			printf("\\0\n");
		printf(" Index : %i\n", stack->index);
		printf("  Next : ");
		if (stack->next != NULL)
			printf("%i\n", stack->next->x);
		else
			printf("\\0\n");
		if (stack->next == NULL)
			printf("[TAIL]\n");
		printf("--------------------------------------\n");
		stack = stack->next;
		i++;
	}	
	printf("\n\n");
}

void	print_both(Node *stack_a, Node *stack_b)
{
	int	dif;
	int	n;
	int	a_len;
	int b_len;
	
	if (!stack_a && !stack_b)
		return ;
	a_len = stack_len(stack_a);
	b_len = stack_len(stack_b);
	if (b_len > a_len)
		dif = b_len;
	else
		dif = a_len;	
	n = 0;
	printf("[STACK_A]              [STACK_B]\n");
	while (n < dif)
	{
		pb_node(stack_a, stack_b, n);
		printf("\n");
		if (stack_a)
			stack_a = stack_a->next;
		if (stack_b)
			stack_b = stack_b->next;
		n++;
	}
	printf("[TAIL]");
	printf("\n\n");
}

void	pb_node(Node *stack_a, Node *stack_b, int nn)
{
		printf("---------------        ---------------\n");
		printf("Node %i is : ", nn);
		if (stack_a)
			printf("%i", stack_a->x);
		else
			printf("--");
		printf("          ");
		printf("Node %i is : ", nn);
		if (stack_b)
			printf("%i\n", stack_b->x);
		else
			printf("--\n");
		printf("---------------        ---------------\n");
		if (stack_a && stack_a->prev && stack_b && stack_b->prev)
			print_line_int(stack_a->prev->x, stack_b->prev->x, "Prev");
		else if (stack_a && stack_a->prev)
			print_line_int(stack_a->prev->x, -1, "Prev");
		else if (stack_b && stack_b->prev)
			print_line_int(-1, stack_b->prev->x, "Prev");
		else
			print_line_int(-1, -1, "Prev");
		if (stack_a && stack_b)
			print_line_int(stack_a->index, stack_b->index, "Index");
		else if (stack_a)
			print_line_int(stack_a->index, -1, "Index");
		else if (stack_b)
			print_line_int(-1, stack_b->index, "Index");
		if (stack_a && stack_b)
			print_line_int(stack_a->push_price, stack_b->push_price, "P_Price");
		else if (stack_a)
			print_line_int(stack_a->push_price, -1, "P_Price");
		else if (stack_b)
			print_line_int(-1, stack_b->push_price, "P_Price");
		if (stack_a && stack_b)
			print_line_int(stack_a->pos, stack_b->pos, "Pos");
		else if (stack_a)
			print_line_int(stack_a->pos, -1, "Pos");
		else if (stack_b)
			print_line_int(-1, stack_b->pos, "Pos");
		if (stack_b && stack_b->target_node)
			print_line_int(-1, stack_b->target_node->x, "T_Node");
		if (stack_a && stack_b)
			print_line_int(stack_a->cheapest, stack_b->cheapest, "Cheapest");
		else if (stack_a)
			print_line_int(stack_a->cheapest, -1, "Cheapest");
		else if (stack_b)
			print_line_int(-1, stack_b->cheapest, "Cheapest");
		if (stack_a && stack_b)
			print_line_int(stack_a->above_median, stack_b->above_median, "Median+");
		else if (stack_a)
			print_line_int(stack_a->above_median, -1, "Median+");
		else if (stack_b)
			print_line_int(-1, stack_b->above_median, "Median+");
		if ((stack_a && stack_a->next && stack_b && stack_b->next))
			print_line_int(stack_a->next->x, stack_b->next->x, "Next");
		else if (stack_a && stack_a->next)
			print_line_int(stack_a->next->x, -1, "Next");
		else if (stack_b && stack_b->next)
			print_line_int(-1, stack_b->next->x, "Next");
		else
			print_line_int(-1, -1, "Next");
		printf("---------------        ---------------\n");
}

static void	print_line_int(int value_a, int value_b, char *str)
{	
		int len;
		int len_a;
		int i = 0;

		len = 20 - ft_strlen(str);
		printf("   %s : ", str);
		if (value_a >= 0)
			len_a = printf("%i", value_a);
		else
			len_a = printf("--");
		while(i++ < (len - len_a))
			printf(" ");
		printf("%s : ", str);
		if (value_b >= 0)
			printf("%i\n", value_b);
		else
			printf("--\n");
}

void print_small(Node *stack_a, Node *stack_b)
{
    const int column_width = 9;
    const int gap_width = 3;

    while (stack_a || stack_b)
    {
		int col = column_width;
		int	gap = gap_width;
        // Print stack_a value (right-aligned in column)
        if (stack_a)
        {
            int len = digit_amount(stack_a->x);
            int padding = column_width - len;
            while (padding-- > 0)
                ft_printf(" ");
            ft_printf("%d", stack_a->x);
            stack_a = stack_a->next;
        }
        else
		{
           while (col-- > 0)
			   ft_printf(" ");
		}
        // Gap between columns
        while (gap-- > 0)
			ft_printf(" ");
		// Print stack_b value (right-aligned in column)
        if (stack_b)
        {
            int len = digit_amount(stack_b->x);
            int padding = column_width - len;
            while (padding-- > 0)
                ft_printf(" ");
            ft_printf("%d", stack_b->x);
            stack_b = stack_b->next;
        }
        ft_printf("\n");
    }
    // Footer
    ft_printf("________a   ________b\n");
    ft_printf("---------------------\n");
}
static int	digit_amount(int i)
{
	int len;

	if (i <= 0)
		len = 1;
	else
		len = 0;;
	while(i != 0)
	{
		i /= 10;
		len++;
	}
	return (len);
}
