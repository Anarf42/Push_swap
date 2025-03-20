/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:54:32 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/03/20 16:19:36 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	int	populate_stack(t_stack *stack, int *numbers, int num_count)
{
	int		i;
	t_node	*new_node;
	t_node	*last_node;

	i = 0;
	last_node = NULL;
	while (i < num_count)
	{
		new_node = init_node(numbers[i]);
		if (!new_node)
			return (1);
		new_node->prev = last_node;
		if (last_node)
			last_node->next = new_node;
		else
			stack->head = new_node;
		last_node = new_node;
		stack->tail = new_node;
		stack->size++;
		i++;
	}
	return (0);
}

static	void	ft_init_algorit(t_stack *stack_a, t_stack *stack_b, int count)
{
	if (stack_a->size == 2)
	{
		if (stack_a->head->value > stack_a->head->next->value)
			swap(stack_a);
	}
	else if (stack_a->size == 3)
		stack_of_three(stack_a);
	else if (stack_a->size == 4)
		stack_of_four(stack_a, stack_b);
	else if (stack_a->size >= 5)
		ksort(stack_a, stack_b, count);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		count;
	int		*numbers;

	if (argc == 1)
		return (1);
	if (check_digits(argc, argv) == -1)
		ft_simple_error("Error");
	count = check_digits(argc, argv);
	if (parse_argum(argc, argv, count) == NULL)
		ft_simple_error("Error");
	numbers = parse_argum(argc, argv, count);
	if (count <= 0 || is_not_duplicate(numbers, count) == -1)
		ft_error_and_free(numbers);
	stack_a = init_stack('a');
	if (!stack_a)
		return (free(numbers), 1);
	stack_b = init_stack('b');
	if (!stack_b)
		return (free(numbers), free_stack(stack_a), 1);
	if (populate_stack(stack_a, numbers, count))
		return (free(numbers), free_stack(stack_a), free_stack(stack_b), 1);
	ft_init_algorit(stack_a, stack_b, count);
	return (finish_free(numbers, stack_a, stack_b), 0);
}
