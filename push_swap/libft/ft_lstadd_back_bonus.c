/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:16:59 by ishchyro          #+#    #+#             */
/*   Updated: 2025/01/17 18:04:11 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	emptylist(t_list **lst, t_list *new)
{
	if (!new || !lst)
	{
		ft_lstclear(*lst);
		free(*lst);
		*lst = NULL;
		return (0);
	}
	return (1);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*head;

	if (emptylist(lst, new))
	{
		if (!*lst)
			*lst = new;
		else
		{
			head = *lst;
			if (head->next)
			{
				head = head->prev;
				new->next = *lst;
				(*lst)->prev = new;
			}
			else
			{
				head->prev = new;
				new->next = head;
			}
			head->next = new;
			new->prev = head;
		}
	}
}
