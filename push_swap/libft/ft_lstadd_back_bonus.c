/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:16:59 by ishchyro          #+#    #+#             */
/*   Updated: 2024/12/15 11:15:50 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*head;

	if (!new || !lst)
		return (ft_lstclear(*lst), exit(-1));
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
