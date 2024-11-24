/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stacksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:56:43 by ishchyro          #+#    #+#             */
/*   Updated: 2024/11/24 02:36:48 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_partition(t_list **stack_a, t_list **stack_b)
{
	int median;

	median = 0;
	if ((ft_lstsize(*stack_a) % 2))
		median = (ft_lstsize(*stack_a) / 2) + 1;
	else
		median = ft_lstsize(*stack_a) / 2;
	while (ft_lstsize(*stack_a) > median)
	{
		if ((*stack_a)->index <= median)
			p(stack_a, stack_b);
		else
			r(stack_a);
		show_stacks(*stack_a, *stack_b);
	}
	ft_printf("--------------------\n");
	return (median);
}

void stacksort(t_list **stack_a, t_list **stack_b)
{
	int i = 10;
	int curr1;
	int next1;
	int prev1;
	int median;

	median = stack_partition(stack_a, stack_b);
	if ((*stack_a)->index > (*stack_a)->next->index)
			s(stack_a);
	while (*stack_b && *stack_a && i--)
	{
		curr1 = (*stack_a)->index;
		next1 = (*stack_a)->next->index;
		prev1 = (ft_lstlast(*stack_a))->index;
		//astacksort(stack_a, stack_b, median);
		show_stacks(*stack_a, *stack_b);
		ft_printf("curr1 = %d, next1 = %d, prev1 = %d\n", curr1, next1, prev1);
		// if ((*stack_b)->next)
		// 	//bstacksort(stack_a, stack_b, median);
		// else
		// 	pa(stack_a, stack_b);
	}
	r(stack_a);
}

// void	astacksort(t_list **stack_a, t_list **stack_b, int median)
// {
// 	if ((*stack_a)->index > (*stack_a)->next->index)
// 		s(stack_a);
// 	else if ((*stack_a)->index > (ft_lstlast(*stack_a))->index)
// 		rra(stack_a);
// 	else
// 		ra(stack_a);
// }

// void	bstacksort(t_list **stack_a, t_list **stack_b, int median)
// {
// 	static int i = 1;
// 	if (((*stack_b)->index + i) == median)
// 	{
// 		pa(stack_a, stack_b);
// 		i++;
// 	}
// 	else if ((*stack_b)->index < (ft_lstlast(*stack_b))->index)
// 		rrb(stack_b);
// 	else if ((*stack_b)->index < (*stack_b)->next->index)
// 		s(stack_b);
// 	else
// 		rb(stack_b);
// }