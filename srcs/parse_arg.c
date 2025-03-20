/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 00:29:41 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/03/20 21:13:13 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	void	ft_skip_space_and_sign(char *str, size_t *i, int *sign)
{
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == 32)
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign = -1;
		(*i)++;
	}
}

static	long	ft_atol(char *str)
{
	size_t		i;
	int			sign;
	long long	res;

	i = 0;
	sign = 1;
	res = 0;
	ft_skip_space_and_sign(str, &i, &sign);
	while (ft_isdigit(str[i]))
		res = (res * 10) + (str[i++] - '0');
	return (res * sign);
}

static	int	check_range(char **string_numbers, int *numbers)
{
	int	i;

	i = 0;
	while (string_numbers[i])
	{
		if (ft_atol(string_numbers[i]) >= 2147483648
			|| ft_atol(string_numbers[i]) <= -2147483649)
		{
			free_split(string_numbers);
			free(numbers);
			return (1);
		}
		i++;
	}
	return (0);
}

int	*parse_argum(int argc, char **argv, int count)
{
	char	**string_numbers;
	int		*numbers;
	int		i;
	int		j;
	int		k;

	numbers = (int *)malloc(sizeof(int) * count);
	if (!numbers)
		return (NULL);
	i = 0;
	j = 0;
	while (++i < argc)
	{
		string_numbers = ft_split(argv[i], ' ');
		if (!string_numbers)
			return (NULL);
		if (check_range(string_numbers, numbers))
			return (NULL);
		k = 0;
		while (string_numbers[k])
			numbers[j++] = ft_atoi(string_numbers[k++]);
		free_split(string_numbers);
	}
	return (numbers);
}
