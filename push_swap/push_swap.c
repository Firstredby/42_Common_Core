/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:49:30 by ishchyro          #+#    #+#             */
/*   Updated: 2024/12/06 23:29:28 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_checker(t_list *stack)
{
	t_list *tmp;

	tmp = stack;
	do
	{
		if (tmp->index > tmp->next->index)
			return (0);
		else
			tmp = tmp->next;
	} while (tmp->next != stack);
	return (1);
}

void parse_input(char **argv, t_list **stack_a)
{
	int i;

	i = 1;
	while(argv[i])
		ft_lstadd_back(stack_a, ft_lstnew(argv[i++]));
}

void value_checker(char **argv)
{
	int i;
	int num;
	char *numstr;
	int values[10000];

	i = 1;
	ft_bzero((char *)values, 10000);
	while(argv[i])
	{
		num = ft_atoi(argv[i]);
		numstr = ft_itoa(num);
		if(!ft_strncmp(numstr, argv[i], ft_strlen(numstr)) && values[num] == 0)
			values[num] = 1;
		else
		{
			ft_printf("Error : %d (argv[%d])\n", ft_atoi(numstr), i);
			free(numstr);
			exit(1);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int *arr;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	value_checker(argv);
	parse_input(argv, &stack_a);
	arr = int_stack(stack_a);
	quicksort(arr, 0, ft_lstsize(stack_a) - 1);
	indexation(stack_a, arr);
	stacksort(&stack_a, &stack_b);
	//show_stacks(stack_a, stack_b);
	if (stack_checker(stack_a))
		return (free(arr), 0);
	else
		return (free(arr), -1);
	return (0);
}