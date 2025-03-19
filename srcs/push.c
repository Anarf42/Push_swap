/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 18:08:11 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/03/19 23:33:52 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_stack *dst, t_stack *src)
{
	t_node	*node_to_push;

	if (!src || !src->head)
		return ;
	node_to_push = src->head;
	src->head = src->head->next;
	if (src->head)
		src->head->prev = NULL;
	else
		src->tail = NULL;
	src->size--;
	node_to_push->next = dst->head;
	node_to_push->prev = NULL;
	if (dst->head)
		dst->head->prev = node_to_push;
	dst->head = node_to_push;
	if (!dst->tail)
		dst->tail = node_to_push;
	dst->size++;
	if (src->name == 'b' && dst->name == 'a')
		ft_printf("pa\n");
	else if (src->name == 'a' && dst->name == 'b')
		ft_printf("pb\n");
}
