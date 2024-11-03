/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SortAlg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 10:06:19 by ishchyro          #+#    #+#             */
/*   Updated: 2024/11/03 14:30:37 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_list **stack_a, t_list **stack_b)
{
	int i;

	i = 0;
	while(ft_lstsize(*stack_a) > 3)
		stack_divide(stack_a, stack_b);
	while(i < 3)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
		{
			sa(stack_a);
			i = 0;
		}
		i++;
	}
}

void	stack_divide(t_list **stack_a, t_list **stack_b)
{
	int i;
	int len;
	int median;

	i = 0;
	len = ft_lstsize(*stack_a);
	median = len / 2;
	while (i <= median)
	{
		pb(stack_a, stack_b);
		i++;
	}
}
