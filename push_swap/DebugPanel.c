#include "push_swap.h"

void show_stack(t_list *stack, char name)
{
	t_list *tmp;

	tmp = stack;
	ft_printf("Stack %c\t|\n", name);
	while (tmp)
	{
		ft_printf("%s\t|\n", (char *)tmp->content);
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
			ft_printf("%s\t|\t", (char *)tmp->content);
			tmp = tmp->next;
		}
		else
			ft_printf("\t|\t");
		if (tmp2)
		{
			ft_printf("%s\n", (char *)tmp2->content);
			tmp2 = tmp2->next;
		}
		else
			ft_printf("\n");
	}
	ft_printf("\n\n");
}