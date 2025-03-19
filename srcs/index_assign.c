/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_assign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:57:13 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/03/19 23:33:19 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap_int(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	selection_sort_ints(int	*str, int size)
{
	int	min_index;
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		min_index = i;
		j = i + 1;
		while (j < size)
		{
			if (str[j] < str[min_index])
				min_index = j;
			j++;
		}
		ft_swap_int(&str[i], &str[min_index]);
		i++;
	}
}

void	assign_sorted_index(t_stack *stack_a, int *sorted_numbers, int count)
{
	t_node	*current_node;
	int		found;
	int		i;

	current_node = stack_a->head;
	while (current_node)
	{
		found = 0;
		i = 0;
		while (i < count)
		{
			if (current_node->value == sorted_numbers[i])
			{
				current_node->s_index = i;
				found = 1;
				break ;
			}
			i++;
		}
		if (!found)
			ft_printf("ERROR: didn't find value %d\n", current_node->value);
		current_node = current_node->next;
	}
}

void	index_stack(t_stack *stack, int size)
{
	t_node	*current;
	int		*sorted_numbers;
	int		i;

	if (!stack || stack->size == 0)
		return ;
	sorted_numbers = malloc(sizeof(int) * size);
	if (!sorted_numbers)
		return ;
	current = stack->head;
	i = 0;
	while (i < size)
	{
		sorted_numbers[i] = current->value;
		current = current->next;
		i++;
	}
	selection_sort_ints(sorted_numbers, size);
	assign_sorted_index(stack, sorted_numbers, size);
	free(sorted_numbers);
}

int	find_pos_index_stack(t_stack *stack, int target_index)
{
	t_node	*current_node;
	int		i;

	if (!stack || !stack->head)
		return (-1);
	current_node = stack->head;
	i = 0;
	while (current_node)
	{
		if (current_node->s_index == target_index)
			return (i);
		current_node = current_node->next;
		i++;
	}
	return (-1);
}
