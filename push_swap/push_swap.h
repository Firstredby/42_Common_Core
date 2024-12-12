/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:49:43 by ishchyro          #+#    #+#             */
/*   Updated: 2024/12/08 19:25:00 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "./libft/libft.h"
# include <math.h>

//quicksort operations
int		*int_stack(t_list *stack); //creating array from stack
void	swap(int *a, int *b); //swapping two values
int		arr_div(int *arr, int start, int end); //dividing array
void	quicksort(int *arr, int start, int end); //sorting array
void	indexation(t_list *stack, int *arr); //indexing stack

//stacksort operations
int		stack_partition(t_list **stack_a, t_list **stack_b);
void	stacksort(t_list **stack_a, t_list **stack_b);
int		median_seek(t_list *stack);
void	simple_sort(t_list **stack_a, t_list **stack_b);
int		best_move(t_list **stack_b, int max);
int		max_index(t_list **stack_a);
int		max_to_push(t_list **stack_a, t_list **stack_b, int max);

//main operations
void	parse_input(char **argv, t_list **stack_a); //parsing input from argv
void	value_checker(int argc, char **argv); //checking and verifying input
int		repeat_num(int *values, int size, int num); //checking for repeating numbers
int		stack_checker(t_list *stack);

//sort moves
void	p(t_list **stack_a, t_list **stack_b); //pushing values
void	p_continue(t_list **stack_a, t_list **stack_b); //additional function for p
void	s(t_list **stack); //swapping first two values in stack
void	ss(t_list **stack_a, t_list **stack_b); //swapping first two values in both stacks
void	r(t_list **stack); //rotating stack upwards
void	rr(t_list **stack_a, t_list **stack_b); //rotating both stacks upwards
void	rev_r(t_list **stack); //rotating stack downwards
void	rrr(t_list **stack_a, t_list **stack_b); //rotating both stacks downwards
int		echo(t_list **stack_a, t_list **stack_b, char *input); //executing moves
void	echos(t_list **stack_a, t_list **stack_b, int commands, ...); //executing multiple moves

//for debug
void	show_stack(t_list *stack, char name);
void	show_stacks(t_list *stack_a, t_list *stack_b);
void	show_array(int *arr, int size);
void	show_stack_indexes(t_list *stack);
void	steps_div();
#endif