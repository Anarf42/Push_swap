/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 18:51:48 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/03/19 23:24:18 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	int	ft_sqrt(int size)
{
	int	res;

	res = 0;
	while (res * res <= size)
		res++;
	res--;
	return (res);
}

int	chunk(int size)
{
	return (ft_sqrt(size));
}

void	ft_error_and_free(int *numbers)
{
	ft_putendl_fd("Error", 2);
	free(numbers);
	exit(255);
}

void	ft_simple_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(255);
}

void	finish_free(int *numbers, t_stack *stack_a, t_stack *stack_b)
{
	free(numbers);
	free_stack(stack_a);
	free_stack(stack_b);
}
