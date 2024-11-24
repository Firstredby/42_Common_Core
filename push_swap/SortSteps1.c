/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SortSteps1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:18:32 by ishchyro          #+#    #+#             */
/*   Updated: 2024/11/24 03:37:33 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_list **stack)
{
	char	*tmp;
	int		tmp2;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = (char *)(*stack)->value;
	tmp2 = (*stack)->index;
	(*stack)->value = (*stack)->next->value;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->value = tmp;
	(*stack)->next->index = tmp2;
}

void	p(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (*stack_a == (*stack_a)->next)
		return p_continue(stack_a, stack_b);
	if (!*stack_b)
	{
		*stack_b = *stack_a;
		*stack_a = (*stack_a)->next;
		(*stack_a)->prev = (*stack_a)->prev->prev;
		(*stack_a)->prev->next = *stack_a;
		(*stack_b)->next = *stack_b;
		(*stack_b)->prev = *stack_b;
	}
	else
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		(*stack_a)->prev = (*stack_a)->prev->prev;
		(*stack_a)->prev->next = *stack_a;
		tmp->next = *stack_b;
		tmp->prev = (*stack_b)->prev;
		(*stack_b)->prev->next = tmp;
		(*stack_b)->prev = tmp;
		*stack_b = tmp;
	}
}

void	p_continue(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_a;
	(*stack_a)->next = NULL;
	(*stack_a)->prev = NULL;
	tmp->next = *stack_b;
	tmp->prev = (*stack_b)->prev;
	(*stack_b)->prev->next = tmp;
	(*stack_b)->prev = tmp;
	*stack_b = tmp;
	*stack_a = NULL;
}

void	r(t_list **stack)
{
	if (!*stack || !(*stack)->prev)
		return ;
	*stack = (*stack)->next;
}

void	rev_r(t_list **stack)
{
	if (!*stack || !(*stack)->prev)
		return ;
	*stack = (*stack)->prev;
}
