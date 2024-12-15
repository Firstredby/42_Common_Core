/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stacksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:56:43 by ishchyro          #+#    #+#             */
/*   Updated: 2024/12/15 17:33:10 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stacksort(t_list **stack_a, t_list **stack_b)
{
	int	max;

	while (ft_lstsize(*stack_a) > 3)
		stack_partition(stack_a, stack_b);
	max = max_index(stack_a) - 1;
	if (!stack_checker(*stack_a))
		simple_sort(stack_a, stack_b);
	while (*stack_b)
		max = max_to_push(stack_a, stack_b, max);
}

int	stack_partition(t_list **stack_a, t_list **stack_b)
{
	int	median;
	int	moves;

	median = 0;
	moves = ft_lstsize(*stack_a);
	median = median_seek(*stack_a);
	while (moves-- && ft_lstsize(*stack_a) > 3)
	{
		if ((*stack_a)->index < median)
			echo(stack_a, stack_b, "pb");
		else
			echo(stack_a, stack_b, "ra");
	}
	return (median);
}

int	max_to_push(t_list **stack_a, t_list **stack_b, int max)
{
	while (*stack_b)
	{
		if ((*stack_b)->index == max)
		{
			echo(stack_a, stack_b, "pa");
			max--;
			break ;
		}
		else if ((*stack_b)->next->index == max)
			echo(stack_a, stack_b, "sb");
		else
		{
			if (best_move(stack_b, max) > 0)
				echo(stack_a, stack_b, "rrb");
			else
				echo(stack_a, stack_b, "rb");
		}
	}
	return (max);
}

void	simple_sort(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a)->index > (*stack_a)->next->index
		&& (*stack_a)->index == (*stack_a)->prev->index + 1)
		echo(stack_a, stack_b, "ra");
	else if ((*stack_a)->index > (*stack_a)->next->index
		&& (*stack_a)->index > (*stack_a)->prev->index)
		echos(stack_a, stack_b, 2, "sa", "rra");
	else if ((*stack_a)->index > (*stack_a)->next->index
		&& (*stack_a)->index < (*stack_a)->prev->index)
		echo(stack_a, stack_b, "sa");
	else if ((*stack_a)->index < (*stack_a)->next->index
		&& (*stack_a)->index > (*stack_a)->prev->index)
		echo(stack_a, stack_b, "rra");
	else
		echos(stack_a, stack_b, 2, "rra", "sa");
}
