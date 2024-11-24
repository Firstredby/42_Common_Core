/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:49:43 by ishchyro          #+#    #+#             */
/*   Updated: 2024/11/24 03:35:47 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "./libft/libft.h"

//quicksort operations
int		*int_stack(t_list *stack);
void	swap(int *a, int *b);
int		arr_div(int *arr, int start, int end);
void	quicksort(int *arr, int start, int end);
void	indexation(t_list *stack, int *arr);

//stacksort operations
int		stack_partition(t_list **stack_a, t_list **stack_b);
void	stacksort(t_list **stack_a, t_list **stack_b);
void	astacksort(t_list **stack_a, t_list **stack_b, int median);
void	bstacksort(t_list **stack_a, t_list **stack_b, int median);
void	stackcheck(t_list **stack_a, t_list **stack_b);
void	parse_input(char **argv, t_list **stack_a);
void	value_checker(char **argv);

//sort moves
void	p(t_list **stack_a, t_list **stack_b);
void	p_continue(t_list **stack_a, t_list **stack_b);
void	s(t_list **stack);
void	ss(t_list **stack_a, t_list **stack_b);
void	r(t_list **stack);
void	rr(t_list **stack_a, t_list **stack_b);
void	rev_r(t_list **stack);
void	rrr(t_list **stack_a, t_list **stack_b);

//for debug
void	show_stack(t_list *stack, char name);
void	show_stacks(t_list *stack_a, t_list *stack_b);
void	show_array(int *arr, int size);
void	show_stack_indexes(t_list *stack);
void	steps_div();
#endif