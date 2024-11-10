#include "push_swap.h"

void show_stack(t_list *stack_, char name)
{
	t_list	*tmp;

	tmp = stack_;
	ft_printf("Stack %c\t|\n", name);
	while (tmp)
	{
		ft_printf("%s\t|\n", (char *)tmp->value);
		tmp = tmp->next;
	}
}

void show_stacks(t_list *stack_a, t_list *stack_b)
{
	t_list *tmp;
	t_list *tmp2;

	tmp = stack_a;
	tmp2 = stack_b;
	ft_printf("Stack A\t| Stack B\n");
	while (tmp || tmp2)
	{
		if (tmp)
		{
			ft_printf("%s\t|\t", (char *)tmp->value);
			tmp = tmp->next;
		}
		else
			ft_printf("\t|\t");
		if (tmp2)
		{
			ft_printf("%s\n", (char *)tmp2->value);
			tmp2 = tmp2->next;
		}
		else
			ft_printf("\n");
	}
	ft_printf("\n\n");
}

void show_array(int *arr, int size)
{
  	int i;

	i = 1;
	ft_printf("Array of int: \t%d\n", arr[0]);
    while (i < size)
    	ft_printf("\t\t%d\n", arr[i++]);
}