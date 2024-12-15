/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:49:30 by ishchyro          #+#    #+#             */
/*   Updated: 2024/12/15 10:51:14 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_checker(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp->next != stack)
	{
		if (tmp->index > tmp->next->index)
			return (0);
		else
			tmp = tmp->next;
	}
	return (1);
}

void	parse_input(char **argv, t_list **stack_a)
{
	int	i;

	i = 1;
	while (argv[i])
		ft_lstadd_back(stack_a, ft_lstnew(argv[i++]));
}

void	value_checker(int argc, char **argv)
{
	int		i;
	int		num;
	char	*numstr;
	int		*values;

	i = 1;
	values = (int *)ft_calloc(argc, sizeof(int));
	if (!values)
		return (ft_putstr_fd("Error\n", 2), exit(1));
	while (argv[i])
	{
		num = ft_atoi(argv[i]);
		numstr = ft_itoa(num);
		if (!ft_strcmp(numstr, argv[i])
			&& repeat_num(values, argc - 1, num))
			values[i - 1] = num;
		else
			return (free(values), free(numstr),
				ft_putstr_fd("Error\n", 2), exit(1));
		i++;
		free(numstr);
		numstr = NULL;
	}
	free(numstr);
	free(values);
}

int	repeat_num(int *values, int size, int num)
{
	int	i;

	i = 0;
	while (i < size)
		if (values[i++] == num)
			return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*arr;

	stack_a = NULL;
	stack_b = NULL;
	if (argv[1] && !ft_isdigit(argv[1][0]))
		return (ft_putstr_fd("Error\n", 2), -1);
	if (argc <= 2)
		return (0);
	value_checker(argc, argv);
	parse_input(argv, &stack_a);
	arr = int_stack(stack_a);
	if (!arr)
		return (ft_lstclear(stack_a), -1);
	quicksort(arr, 0, ft_lstsize(stack_a) - 1);
	indexation(stack_a, arr);
	stacksort(&stack_a, &stack_b);
	return (free(arr), ft_lstclear(stack_a), 0);
}
