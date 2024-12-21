/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:49:30 by ishchyro          #+#    #+#             */
/*   Updated: 2024/12/21 01:22:11 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_input(char **argv, t_list **stack_a)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		ft_lstadd_back(stack_a, ft_lstnew(argv[i++]));
		if (!*stack_a)
			return (0);
	}
	return (1);
}

void	argclean(char **arg_)
{
	int	i;

	i = 0;
	while (arg_[i])
		free(arg_[i++]);
	free(arg_);
}

char	**argvtoarg(char **argv)
{
	char	**arg_;
	int		i;

	i = 0;
	while (argv[i])
		i++;
	arg_ = ft_calloc(sizeof(char *), i);
	if (!arg_)
		return (NULL);
	i = 0;
	while (argv[i + 1])
	{
		arg_[i] = ft_strdup(argv[i + 1]);
		if (!arg_[i])
			return (argclean(arg_), NULL);
		i++;
	}
	return (arg_);
}

void	sortfunc(char **arg_, int arglen)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*arr;

	stack_a = NULL;
	stack_b = NULL;
	if (!value_checker(arglen, arg_) || !parse_input(arg_, &stack_a))
		return (argclean(arg_));
	if (!stack_checker(stack_a))
		return (argclean(arg_), ft_lstclear(stack_a));
	arr = int_stack(stack_a);
	if (!arr)
		return (argclean(arg_), ft_lstclear(stack_a));
	quicksort(arr, 0, ft_lstsize(stack_a) - 1);
	indexation(stack_a, arr);
	stacksort(&stack_a, &stack_b);
	return (argclean(arg_), free(arr), ft_lstclear(stack_a));
}

int	main(int argc, char **argv)
{
	char	**arg_;
	int		arglen;

	arglen = 0;
	if (argc == 1)
		return (0);
	if (argv[1] && !(ft_isdigit(argv[1][0])
		|| (argv[1][0] == '-' && ft_isdigit(argv[1][1]))))
		return (ft_putstr_fd("Error\n", 2), -1);
	if (argc == 2)
		arg_ = ft_split(argv[1], ' ');
	else
		arg_ = argvtoarg(argv);
	if (!arg_)
		return (-1);
	while (arg_[arglen])
		arglen++;
	sortfunc(arg_, arglen);
	return (0);
}
