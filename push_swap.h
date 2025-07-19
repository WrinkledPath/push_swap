/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywagner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:25:29 by ywagner           #+#    #+#             */
/*   Updated: 2025/07/19 18:42:39 by ywagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_list
{
	int				x;
	int				index;
	int				push_price;
	int				pos;
	bool			cheap;
	bool			above_median;
	struct s_list	*target_node;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

// Linked List Moves
int		handle_args(t_list **stack_a, char **argv, int argc);
int		stack_len(t_list *curr);
int		is_sorted(t_list *head);
int		init_stack_a(t_list **head, char **argv);
int		append_node(t_list **head, int value);
int		free_list(t_list **head);
void	rotate_list(t_list **head);
void	reverse_rotate(t_list **head);
void	push_node(t_list **stack_a, t_list **stack_b);
void	swap(t_list **root);
t_list	*find_last(t_list *stack);
t_list	*create_node(int value);

// Basic Sort
int		get_node_position(t_list *stack, t_list *target);
void	assign_index(t_list *root);
void	sort_pipe(t_list **stack_a, t_list **stack_b);
void	tiny_sort(t_list **root);
t_list	*find_min(t_list *root);
t_list	*find_max(t_list *root);

// Turk Sort
int		same_direction(t_list *node);
void	turk_sort(t_list **stack_a, t_list **stack_b);
void	set_medium(t_list *stack_a, t_list *stack_b);
void	set_pos(t_list *stack_a, t_list *stack_b);
t_list	*turk_assignment(t_list *stack_a, t_list *stack_b);
t_list	*set_cheap(t_list *stack_b);

// Print Functions
void	sa(t_list **root, bool print);
void	ra(t_list **root, bool print);
void	rra(t_list **root, bool print);
void	rb(t_list **root, bool print);
void	rrb(t_list **root, bool print);
void	rr(t_list **stack_a, t_list **stack_b, bool print);
void	rrr(t_list **stack_a, t_list **stack_b, bool print);
void	pa(t_list **stack_a, t_list **stack_b, bool print);
void	pb(t_list **stack_a, t_list **stack_b, bool print);

#endif
