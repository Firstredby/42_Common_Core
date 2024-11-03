/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SortSteps2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:25:19 by ishchyro          #+#    #+#             */
/*   Updated: 2024/11/03 11:28:57 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	last = *stack_a;
	while (last->next)
		last = last->next;
	*stack_a = (*stack_a)->next;
	last->next = tmp;
	tmp->next = NULL;
}

void	rb(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	last = *stack_b;
	while (last->next)
		last = last->next;
	*stack_b = (*stack_b)->next;
	last->next = tmp;
	tmp->next = NULL;
}

void	rra(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
}

void	rrb(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
}