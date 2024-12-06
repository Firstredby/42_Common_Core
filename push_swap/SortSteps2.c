/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SortSteps2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:25:38 by ishchyro          #+#    #+#             */
/*   Updated: 2024/12/06 23:17:28 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_list **stack_a, t_list **stack_b)
{
	return (s(stack_a), s(stack_b));
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	return (r(stack_a), r(stack_b));
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	return (rev_r(stack_a), rev_r(stack_b));
}

int	echo(t_list **stack_a, t_list **stack_b, char *input)
{
	if (ft_strncmp(input, "sa", 3) == 0)
		return (s(stack_a), ft_printf("sa\n"));
	if (ft_strncmp(input, "sb", 3) == 0)
		return (s(stack_b), ft_printf("sb\n"));
	if (ft_strncmp(input, "ss", 3) == 0)
		return (ss(stack_a, stack_b), ft_printf("ss\n"));
	if (ft_strncmp(input, "pa", 3) == 0)
		return (p(stack_b, stack_a), 1);
	if (ft_strncmp(input, "pb", 3) == 0)
		return (p(stack_a, stack_b), 1);
	if (ft_strncmp(input, "ra", 3) == 0)
		return (r(stack_a), ft_printf("ra\n"));
	if (ft_strncmp(input, "rb", 3) == 0)
		return (r(stack_b), ft_printf("rb\n"));
	if (ft_strncmp(input, "rr", 3) == 0)
		return (rr(stack_a, stack_b), ft_printf("rr\n"));
	if (ft_strncmp(input, "rra", 3) == 0)
		return (rev_r(stack_a), ft_printf("rra\n"));
	if (ft_strncmp(input, "rrb", 3) == 0)
		return (rev_r(stack_b), ft_printf("rrb\n"));
	if (ft_strncmp(input, "rrr", 3) == 0)
		return (rrr(stack_a, stack_b), ft_printf("rrr\n"));
	return (0);
}

void	echos(t_list **stack_a, t_list **stack_b, int commands, ...)
{
	int i;
	va_list args;

	va_start(args, commands);
	i = 0;
	while(i < commands)
	{
		char *input = va_arg(args, char *);
		echo(stack_a, stack_b, input);
		i++;
	}
	va_end(args);
}
