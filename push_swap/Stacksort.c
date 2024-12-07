/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stacksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:56:43 by ishchyro          #+#    #+#             */
/*   Updated: 2024/12/06 23:29:07 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_partition(t_list **stack_a, t_list **stack_b)
{
	int median;
	int moves;

	median = 0;
	moves = ft_lstsize(*stack_a);
	median = (int)median_seek(*stack_a);
	while (moves-- && ft_lstsize(*stack_a) > 3)
	{
		if ((*stack_a)->index > median)
			echo(stack_a, stack_b, "pb");
		else
			echo(stack_a, stack_b, "ra");
	}
	return (median);
}

int median_seek(t_list *stack)
{
	t_list *tmp;
	int median;
	int numbers;

	median = numbers = 0;
	tmp = stack;
	do
	{
		median += tmp->index;
		numbers++;
		tmp = tmp->next;	
	} while (tmp != stack);
	return ((median / numbers) + 1);
}

void stacksort(t_list **stack_a, t_list **stack_b)
{
	int moves;
	int ref;

	while(ft_lstsize(*stack_a) > 3)
		stack_partition(stack_a, stack_b);
	if (!stack_checker(*stack_a))
		simple_sort(stack_a, stack_b);
	while (*stack_b)
	{
		ref = median_seek(*stack_b) + 1;
		moves = ft_lstsize(*stack_b);
		main_sort(stack_a, stack_b, ref, moves);
	}
}

int best_move(t_list **stack_b, int min, int ref)
{
	t_list *top;
	t_list *bot;
	int costtop;
	int costbot;

	top = bot = *stack_b;
	costtop = 0;
	costbot = 0;
	do
	{
		if (top->index == top->next->index + 1
			&& top->next->index < ref && top->next->index == min)
			break ;
		else if (top->index < ref && top->index == min)
			break ;
		costtop++;
		top = top->next;
		if (bot->index == bot->next->index + 1
			&& bot->next->index < ref && bot->next->index == min)
			break ;
		else if (bot->index < ref && bot->index == min)
			break ;
		costbot++;
		bot = bot->prev;
	} while (top != bot);
	return (costtop - costbot);
}

void main_sort(t_list **stack_a, t_list **stack_b, int ref, int moves)
{
	int min;

	while(moves--)
	{
		min = (*stack_a)->prev->index + 1;
		if ((*stack_b)->index == (*stack_b)->next->index + 1
			&& (*stack_b)->next->index < ref && (*stack_b)->next->index == min)
			echos(stack_a, stack_b, 4, "pa", "pa", "rr", "rr");
		else if ((*stack_b)->index < ref && (*stack_b)->index == min)
			echos(stack_a, stack_b, 2, "pa", "ra");
		if (!*stack_b)
			break ;
		if (best_move(stack_b, min, ref))
			echo(stack_a, stack_b, "rrb");
		else
			echo(stack_a, stack_b, "rb");
	}
}

void simple_sort(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a)->index == 1
		&& (*stack_a)->next->index == 2)
		echo(stack_a, stack_b, "rra");
	else if ((*stack_a)->index == 1
		&& (*stack_a)->next->index == 0)
		echo(stack_a, stack_b, "sa");
	else if ((*stack_a)->index == 2
		&& (*stack_a)->next->index == 0)
		echo(stack_a, stack_b, "ra");
	else if ((*stack_a)->index == 2
		&& (*stack_a)->next->index == 1)
	{
		echo(stack_a, stack_b, "sa");
		echo(stack_a, stack_b, "rra");	
	}	
	else 
	{
		echo(stack_a, stack_b, "rra");
		echo(stack_a, stack_b, "sa");
	}
}
