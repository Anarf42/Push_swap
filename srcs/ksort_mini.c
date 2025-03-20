/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort_mini.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:14:14 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/03/20 23:36:34 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	stack_of_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->head->value;
	b = stack->head->next->value;
	c = stack->head->next->next->value;
	if (a > b && a < c)
		swap(stack);
	else if (a > b && a > c && b > c)
	{
		rotate(stack, TRUE);
		swap(stack);
	}
	else if (a < b && b > c && a < c)
	{
		reverse(stack, TRUE);
		swap(stack);
	}
	else if (a < b && a > c)
		reverse(stack, TRUE);
	else if (a > b && a > c && b < c)
		rotate(stack, TRUE);
}

void	stack_of_four(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a);
	stack_of_three(stack_a);
	if (stack_b->head->value < stack_a->head->value)
		push(stack_a, stack_b);
	else if (stack_b->head->value > stack_a->tail->value)
	{
		push(stack_a, stack_b);
		rotate(stack_a, TRUE);
	}
	else if (stack_b->head->value > stack_a->tail->prev->value)
	{
		reverse(stack_a, TRUE);
		push(stack_a, stack_b);
		rotate(stack_a, TRUE);
		rotate(stack_a, TRUE);
	}
	else if (stack_b->head->value > stack_a->head->value)
	{
		push(stack_a, stack_b);
		swap(stack_a);
	}
}

void	stack_of_five(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (i++ <= stack_a->size && stack_b->size != 2)
	{
		if (stack_a->head->s_index == 0)
			push(stack_b, stack_a);
		else if (stack_a->head->s_index == 1)
			push(stack_b, stack_a);
		else
			rotate(stack_a, TRUE);
	}
	stack_of_three(stack_a);
	if (stack_b->head->value > stack_b->head->next->value && stack_b->size > 1)
	{
		push(stack_a, stack_b);
		push(stack_a, stack_b);
	}
	else if (stack_b->head->value < stack_b->head->next->value
		&& stack_b->size > 1)
	{
		swap(stack_b);
		push(stack_a, stack_b);
		push(stack_a, stack_b);
	}
}
