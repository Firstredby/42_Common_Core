/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:39:43 by ishchyro          #+#    #+#             */
/*   Updated: 2024/11/24 08:09:15 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;
	t_list	*end;

	i = 1;
	if (!lst)
		return (0);
	end = lst->prev;
	if (end->prev->value == lst->value)
		return (2);
	while (lst->value != end->value)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
