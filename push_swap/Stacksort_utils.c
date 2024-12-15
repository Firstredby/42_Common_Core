/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stacksort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:56:43 by ishchyro          #+#    #+#             */
/*   Updated: 2024/12/15 17:26:18 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	median_seek(t_list *stack)
{
	t_list	*tmp;
	int		median;
	int		numbers;

	median = 0;
	numbers = 0;
	tmp = stack;
	while (tmp)
	{
		median += tmp->index;
		numbers++;
		tmp = tmp->next;
		if (tmp == stack)
			break ;
	}
	if (ft_lstsize(stack) > 250)
		return ((median / numbers) - numbers / 2.68);
	if (ft_lstsize(stack) > 100)
		return ((median / numbers) - numbers / 3.9);
	if (ft_lstsize(stack) > 30)
		return ((median / numbers) - numbers / 7.5);
	if (ft_lstsize(stack) > 10)
		return ((median / numbers) - numbers / 10.2);
	return ((median / numbers));
}

int	max_index(t_list **stack_a)
{
	t_list	*tmp;
	int		max;

	tmp = (*stack_a)->next;
	max = tmp->index;
	while (tmp != (*stack_a))
	{
		if (tmp->index < max)
			max = tmp->index;
		tmp = tmp->next;
	}
	if (tmp->index < max)
		max = tmp->index;
	return (max);
}

int	best_move(t_list **stack_b, int max)
{
	t_list	*top;
	t_list	*bot;
	int		costtop;
	int		costbot;

	top = *stack_b;
	bot = *stack_b;
	costtop = 0;
	costbot = 0;
	while (top->next != bot)
	{
		if (top->index == max)
			return (costtop - costbot - 1);
		costtop++;
		top = top->next;
		if (bot->index == max)
			return (costtop - costbot + 1);
		costbot++;
		bot = bot->prev;
	}
	return (costtop - costbot);
}
