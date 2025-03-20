/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:29:24 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/03/20 23:36:53 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	int	ft_aux_is_sorted(t_stack *stack, int *numers, int size)
{
	t_node	*current_node;
	int		node_index;
	int		i;
	int		j;

	current_node = stack->head;
	j = 0;
	node_index = 0;
	while (current_node)
	{
		i = node_index;
		while (i < size)
		{
			if (current_node->value > numers[i])
				j += 1;
			i++;
		}
		current_node = current_node->next;
		node_index++;
	}
	return (j);
}

int	ft_is_sorted(t_stack *stack, int size)
{
	t_node	*current_node;
	t_node	*current_node2;
	int		*sorted_numbers;
	int		i;
	int		j;

	current_node = stack->head;
	current_node2 = stack->head;
	sorted_numbers = malloc(sizeof(int) * size);
	if (!sorted_numbers)
		return (0);
	i = 0;
	while (i < size)
	{
		sorted_numbers[i] = current_node->value;
		current_node = current_node->next;
		i++;
	}
	j = ft_aux_is_sorted(stack, sorted_numbers, size);
	return (free(sorted_numbers), j);
}
