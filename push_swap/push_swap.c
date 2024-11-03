/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:49:30 by ishchyro          #+#    #+#             */
/*   Updated: 2024/11/03 14:30:45 by ishchyro         ###   ########.fr       */
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
	ft_bzero((char *)values, 10);
	while(argv[i])
	{
		num = ft_atoi(argv[i]);
		numstr = ft_itoa(num);
		if (!values[ft_atoi(numstr)] && (ft_atoi(numstr) > -2147483648 && ft_atoi(numstr) < 2147483647))
			values[ft_atoi(argv[i++])] = 1;
		else
		{
			ft_printf("Error : %d (argv[%d])\n", ft_atoi(numstr), i);
			exit(1);
		}
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	value_checker(argv);
	parse_input(argv, &stack_a);
	show_stack(stack_a, 'A');
	ft_printf("\n");
	sort(&stack_a, &stack_b);
	//show_stacks(stack_a, stack_b);
	return (0);
}