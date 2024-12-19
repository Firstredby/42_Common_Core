#include "push_swap.h"

void show_stack(t_list *stack_, char name)
{
	t_list	*tmp;

	tmp = stack_->prev;
	ft_printf("Stack %c\t|\n", name);
	while (stack_ != tmp)
	{
		ft_printf("%s(%d)\t|\n", (char *)stack_->value, stack_->index);
		stack_ = stack_->next;
	}
	ft_printf("%s(%d)\t|\n", (char *)stack_->value, stack_->index);
	steps_div();
}

void show_stacks(t_list *stack_a, t_list *stack_b)
{
	if (stack_a == NULL)
		return show_stack(stack_b, 'b');
	else if (stack_b == NULL)
		return show_stack(stack_a, 'a');
	int anchor_a = (*stack_a).index;
	int anchor_b = (*stack_b).index;
	int eof_a = 0;
	int eof_b = 0;
	int i = 15;
	ft_printf("Stack A\t| Stack B\n");
	while ((anchor_a || anchor_b) && i--)
	{
		if (eof_a)
			ft_printf("\t|\t");	
		else
			ft_printf("%s(%d)\t|\t", (char *)stack_a->value, stack_a->index);
		if (eof_b)
			ft_printf("\n");
		else
			ft_printf("%s(%d)\n", (char *)stack_b->value, stack_b->index);
		stack_a = stack_a->next;
		stack_b = stack_b->next;
		if (stack_a->index == anchor_a)
			eof_a = 1;
		if (stack_b->index == anchor_b)
			eof_b = 1;
		if (eof_a && eof_b)
			break;
	}
	steps_div();
}

void show_array(int *arr)
{
  	int i;

	i = 0;
	//ft_printf("Array of int: \t%d\n", arr[0]);
    while (arr[i])
		ft_printf("\t\t%d\n", arr[i++]);
	steps_div();
}

void show_stack_indexes(t_list *stack)
{
	t_list *tmp;

	tmp = stack;
	while (tmp)
	{
		ft_printf("Index: %d\tValue: %s\n", tmp->index, (char *)tmp->value);
		tmp = tmp->next;
	}
	steps_div();
}

void	steps_div()
{
	ft_printf("--------------------\n");
}