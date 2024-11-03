/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:34:48 by ishchyro          #+#    #+#             */
/*   Updated: 2024/09/18 16:54:58 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*begin;

	while (*lst)
	{
		begin = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = begin;
	}
	lst = NULL;
}
