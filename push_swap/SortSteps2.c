/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SortSteps2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:25:38 by ishchyro          #+#    #+#             */
/*   Updated: 2024/11/24 02:34:04 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_list **stack_a, t_list **stack_b)
{
	s(stack_a);
	s(stack_b);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	r(stack_a);
	r(stack_b);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rev_r(stack_a);
	rev_r(stack_b);
}