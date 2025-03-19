/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:41:05 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/03/19 23:33:41 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*init_stack(char name_stack)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->name = name_stack;
	stack->head = NULL;
	stack->size = 0;
	stack->tail = NULL;
	return (stack);
}

t_node	*init_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->index = 0;
	node->next = NULL;
	node->prev = NULL;
	node->value = value;
	node->pos_in_stack = 0;
	node->s_index = 0;
	return (node);
}

static	void	ft_free_nodes(t_node **node)
{
	t_node	*tmp;

	while (*node)
	{
		tmp = (*node)->next;
		free(*node);
		*node = tmp;
	}
	*node = NULL;
}

void	free_stack(t_stack *stack)
{
	if (!stack)
		return ;
	ft_free_nodes(&stack->head);
	free(stack);
}

void	free_split(char	**result)
{
	size_t	i;

	i = 0;
	if (result)
	{
		while (result && result[i])
		{
			if (result[i] != NULL)
			{
				free(result[i]);
				result[i] = NULL;
			}
			i++;
		}
		free(result);
		result = NULL;
	}
}
