/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:09:18 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/03/20 22:30:54 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ksort_1(t_stack *a, t_stack *b, int size)
{
	int	chunk_size;
	int	i;

	i = 0;
	chunk_size = chunk(size);
	while (a->head)
	{
		if (a->head->s_index <= i)
		{
			push(b, a);
			i++;
		}
		else if (a->head->s_index <= i + chunk_size)
		{
			push(b, a);
			i++;
			if (!(a->head->s_index <= i + chunk_size))
				rr(a, b, FALSE);
			else
				rotate(b, TRUE);
		}
		else
			rotate(a, TRUE);
	}
}

void	ksort_2(t_stack *a, t_stack *b, int size)
{
	int	target;
	int	pos;
	int	half;
	int	count_mov;

	target = size - 1;
	while (target >= 0)
	{
		pos = find_pos_index_stack(b, target);
		half = b->size;
		count_mov = half - pos;
		if (pos <= count_mov)
		{
			while (b->head->s_index != target)
				rotate(b, TRUE);
		}
		else
			while (b->head->s_index != target)
				reverse(b, TRUE);
		push(a, b);
		target--;
	}
}

void	ksort(t_stack *a, t_stack *b, int size)
{
	index_stack(a, size);
	if (ft_is_sorted(a, size))
	{
		if (size == 5)
			stack_of_five(a, b);
		else
		{
			ksort_1(a, b, size);
			ksort_2(a, b, size);
		}
	}
}
