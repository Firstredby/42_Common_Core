/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:49:30 by ishchyro          #+#    #+#             */
/*   Updated: 2024/11/24 03:38:59 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	// show_stack(stack_a, 'a');
	arr = int_stack(stack_a);
	quicksort(arr, 0, ft_lstsize(stack_a) - 1);
	indexation(stack_a, arr);
	show_stacks(stack_a, stack_b);
	p(&stack_a, &stack_b);
	ft_printf("first push\n");
	show_stacks(stack_a, stack_b);
	ft_printf("second push\n");
	p(&stack_a, &stack_b);
	show_stacks(stack_a, stack_b);
	ft_printf("third push\n");
	p(&stack_a, &stack_b);
	show_stacks(stack_a, stack_b);
	ft_printf("forth push\n");
	p(&stack_a, &stack_b);
	show_stacks(stack_a, stack_b);
	ft_printf("fifth push\n");
	p(&stack_a, &stack_b);
	show_stacks(stack_a, stack_b);
	ft_printf("sixth push\n");
	p(&stack_a, &stack_b);
	show_stacks(stack_a, stack_b);
	ft_printf("seventh push\n");
	p(&stack_a, &stack_b);
	show_stacks(stack_a, stack_b);
	ft_printf("last push\n");
	p(&stack_a, &stack_b);
	show_stacks(stack_a, stack_b);
	ft_printf("push back\n");
	p(&stack_b, &stack_a);
	show_stacks(stack_a, stack_b);
	//show_stack(stack_a, 'a');
	// show_stacks(stack_a, stack_b);
	free(arr);
	return (0);
}