/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 18:24:48 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/03/19 23:36:02 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate(t_stack *stack, int i)
{
	t_node	*new_head;
	t_node	*new_tail;

	if (stack->size > 1)
	{
		new_head = stack->head->next;
		new_tail = stack->head;
		new_head->prev = NULL;
		stack->head = new_head;
		stack->tail->next = new_tail;
		new_tail->prev = stack->tail;
		new_tail->next = NULL;
		stack->tail = new_tail;
	}
	if (i == 1)
	{
		if (stack->name == 'a')
			ft_printf("ra\n");
		else
			ft_printf("rb\n");
	}
}

void	rr(t_stack *stack_a, t_stack *stack_b, int i)
{
	rotate(stack_a, i);
	rotate(stack_b, i);
	ft_printf("rr\n");
}
