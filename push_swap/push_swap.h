/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:49:43 by ishchyro          #+#    #+#             */
/*   Updated: 2024/11/10 14:57:55 by ishchyro         ###   ########.fr       */
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

//values input + check
void	parse_input(char **argv, t_list **stack_a);
void	value_checker(char **argv);

//sort moves
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

//for debug
void	show_stack(t_list *stack, char name);
void	show_stacks(t_list *stack_a, t_list *stack_b);
void	show_array(int *arr, int size);

#endif