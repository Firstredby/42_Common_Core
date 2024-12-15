/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SortSteps2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:25:38 by ishchyro          #+#    #+#             */
/*   Updated: 2024/12/15 10:53:27 by ishchyro         ###   ########.fr       */
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
	if (ft_strcmp(input, "sa") == 0)
		return (s(stack_a), ft_printf("sa\n"));
	if (ft_strcmp(input, "sb") == 0)
		return (s(stack_b), ft_printf("sb\n"));
	if (ft_strcmp(input, "ss") == 0)
		return (ss(stack_a, stack_b), ft_printf("ss\n"));
	if (ft_strcmp(input, "pa") == 0)
		return (p(stack_b, stack_a), ft_printf("pa\n"));
	if (ft_strcmp(input, "pb") == 0)
		return (p(stack_a, stack_b), ft_printf("pb\n"));
	if (ft_strcmp(input, "ra") == 0)
		return (r(stack_a), ft_printf("ra\n"));
	if (ft_strcmp(input, "rb") == 0)
		return (r(stack_b), ft_printf("rb\n"));
	if (ft_strcmp(input, "rr") == 0)
		return (rr(stack_a, stack_b), ft_printf("rr\n"));
	if (ft_strcmp(input, "rra") == 0)
		return (rev_r(stack_a), ft_printf("rra\n"));
	if (ft_strcmp(input, "rrb") == 0)
		return (rev_r(stack_b), ft_printf("rrb\n"));
	if (ft_strcmp(input, "rrr") == 0)
		return (rrr(stack_a, stack_b), ft_printf("rrr\n"));
	return (0);
}

void	echos(t_list **stack_a, t_list **stack_b, int commands, ...)
{
	int		i;
	va_list	args;
	char	*input;

	va_start(args, commands);
	i = 0;
	while (i < commands)
	{
		input = va_arg(args, char *);
		echo(stack_a, stack_b, input);
		i++;
	}
	va_end(args);
}
