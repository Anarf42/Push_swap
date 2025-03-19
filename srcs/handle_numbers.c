/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:45:36 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/03/19 23:27:48 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_not_duplicate(int *numbers, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (numbers[i] == numbers[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_digits(int argc, char **argv)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-' && j == 0)
				j++;
			if (argv[i][j] == '-' && argv[i][j - 1] != ' ')
				return (-1);
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' '
				&& argv[i][j] != '-')
				return (-1);
			if (ft_isdigit(argv[i][j]) && (argv[i][j + 1] == ' '
				|| argv[i][j + 1] == '\0'))
				count += 1;
			j++;
		}
	}
	return (count);
}
