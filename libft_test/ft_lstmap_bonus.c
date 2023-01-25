/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:05:51 by jmeruma           #+#    #+#             */
/*   Updated: 2022/11/18 11:34:43 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*start;
	void	*content;

	if (!f || !lst)
		return (NULL);
	content = f(lst->content);
	node = ft_lstnew(content);
	if (!node)
		return (del(content), NULL);
	start = node;
	lst = lst->next;
	while (lst)
	{
		content = f(lst->content);
		node->next = ft_lstnew(content);
		if (!node->next)
			return (del(content), ft_lstclear(&start, del), NULL);
		node = node->next;
		lst = lst->next;
	}
	return (start);
}
