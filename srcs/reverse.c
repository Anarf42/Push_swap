/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 18:36:12 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/03/19 23:22:52 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse(t_stack *stack, int c)
{
	int	i;
	int	size;

	if (!stack || !stack->head || !stack->head->next)
		return ;
	size = stack->size;
	i = 0;
	while (i < size - 1)
	{
		rotate(stack, FALSE);
		i++;
	}
	if (c == 1)
	{
		if (stack->name == 'a')
			ft_printf("rra\n");
		else
			ft_printf("rrb\n");
	}
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse(stack_a, FALSE);
	reverse(stack_b, FALSE);
	ft_printf("rrr\n");
}
