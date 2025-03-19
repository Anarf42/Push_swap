/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:00:39 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/03/19 23:51:00 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include <limits.h>
# define TRUE	1
# define FALSE	0

/* -- structure for a nodo -- */
typedef struct s_node
{
	int				value;
	int				index;
	int				s_index;
	int				pos_in_stack;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

/* -- structure for a stack -- */
typedef struct s_stack
{
	char	name;
	t_node	*head;
	t_node	*tail;
	int		size;
}	t_stack;

/* -- index_assign.c -- */
void	assign_sorted_index(t_stack *stack_a, int *sorted_numbers, int count);
void	selection_sort_ints(int	*str, int size);
void	index_stack(t_stack *stack, int size);
int		find_pos_index_stack(t_stack *stack, int target_index);

/* -- init_and_free -- */
void	free_stack(t_stack *stack);
void	free_split(char	**result);
t_stack	*init_stack(char name_stack);
t_node	*init_node(int value);

/* -- handle_numbers -- */
int		is_not_duplicate(int *numbers, int count);
int		check_digits(int argc, char **argv);

/* -- swap -> sa, sb and ss -- */
void	swap(t_stack *stack);
void	ss(t_stack *stack_a, t_stack *stack_b);

/* -- push -> pa and pb -- */
void	push(t_stack *dst, t_stack *src);

/* -- rotate -> ra, rb and rr -- */
void	rotate(t_stack *stack, int i);
void	rr(t_stack *stack_a, t_stack *stack_b, int i);

/* -- reverse -> rra, rrb and rrr -- */
void	reverse(t_stack *stack, int i);
void	rrr(t_stack *stack_a, t_stack *stack_b);

/* -- utils -> chunk -- */
int		chunk(int size);
void	ft_error_and_free(int *numbers);
void	ft_simple_error(char *str);
void	finish_free(int *numbers, t_stack *stack_a, t_stack *stack_b);

/* -- ksort -> ksort1 and ksort2 */
void	ksort(t_stack *a, t_stack *b, int size);
void	ksort_1(t_stack *a, t_stack *b, int size);
void	ksort_2(t_stack *a, t_stack *b, int size);

/*  push_swap */
int		main(int argc, char *argv[]);

/* -- ksort_mini  -- */
void	stack_of_three(t_stack *stack);
void	stack_of_four(t_stack *stack_a, t_stack *stack_b);
void	stack_of_five(t_stack *stack_a, t_stack *stack_b);

/* -- parse_arg  -- */
int		*parse_argum(int argc, char **argv, int count);

#endif