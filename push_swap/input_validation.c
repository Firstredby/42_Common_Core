/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:39:30 by ishchyro          #+#    #+#             */
/*   Updated: 2025/01/04 19:18:31 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	value_checker(int argc, char **argv)
{
	int	i;
	int	j;
	int	*values;

	i = 0;
	values = (int *)ft_calloc(argc, sizeof(int));
	if (!values)
		return (ft_putstr_fd("Error\n", 2), 0);
	while (argv[i])
	{
		j = 0;
		if (argv[i][0] == '-')
			j++;
		while (ft_isdigit(argv[i][j]))
			j++;
		if ((int)ft_strlen(argv[i]) == j && j <= 11
			&& repeat_num(values, argc, ft_atoi(argv[i])))
			values[i] = ft_atoi(argv[i]);
		else
			return (free(values), ft_putstr_fd("Error\n", 2), 0);
		i++;
	}
	if (i == 1)
		return (free(values), 0);
	return (free(values), 1);
}

int	repeat_num(int *values, int size, long int num)
{
	int			i;
	static int	zero;

	i = 0;
	while (i < size)
	{
		if (num == 0)
		{
			zero++;
			break ;
		}
		else if (values[i++] == num || num > 2147483647 || num < -2147483648)
			return (0);
	}
	if (zero > 1)
		return (0);
	return (1);
}
