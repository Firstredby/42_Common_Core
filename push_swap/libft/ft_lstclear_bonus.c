/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:34:48 by ishchyro          #+#    #+#             */
/*   Updated: 2024/12/15 11:16:51 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list *lst)
{
	t_list	*curr;
	t_list	*next_node;

	if (!lst || !lst->next || !lst->prev)
		return ;
	curr = lst;
	curr->prev->next = NULL;
	while (curr != NULL)
	{
		next_node = curr->next;
		curr->value = NULL;
		free(curr);
		curr = next_node;
	}
}
