/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SortAlg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 10:06:19 by ishchyro          #+#    #+#             */
/*   Updated: 2024/11/10 14:40:14 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *int_stack(t_list *stack)
{
	int i;
	int *arr;

	arr = malloc(sizeof(int) * ft_lstsize(stack));
	if (!arr)
		exit(-1);
	i = 0;
	while (stack && stack->next)
	{
		arr[i++] = ft_atoi(stack->value);
		stack = stack->next;
	}
	arr[i] = ft_atoi(stack->value);
	return (arr);
}

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int arr_div(int *arr, int start, int end)
{
    int pivot;
    int i;
    int j;

    pivot = arr[end];
    i = start - 1;
    j = start;
    while (j <= end - 1) 
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
        j++;
    }
    swap(&arr[i + 1], &arr[end]);
    return (i + 1);
}

void    quicksort(int *arr, int start, int end)
{
    int pivot_index;

    if (start < end)
    {
        pivot_index = arr_div(arr, start, end);
        quicksort(arr, start, pivot_index - 1);
        quicksort(arr, pivot_index + 1, end);
    }
}
