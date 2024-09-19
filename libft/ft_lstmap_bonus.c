/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:27:17 by ishchyro          #+#    #+#             */
/*   Updated: 2024/09/18 16:53:44 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*cpylst;

	newlst = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		cpylst = malloc(sizeof(t_list));
		if (!cpylst)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		cpylst->content = f(lst->content);
		cpylst->next = NULL;
		ft_lstadd_back(&newlst, cpylst);
		lst = lst->next;
	}
	return (newlst);
}
