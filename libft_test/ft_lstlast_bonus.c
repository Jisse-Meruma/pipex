/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmeruma <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 15:05:51 by jmeruma       #+#    #+#                 */
/*   Updated: 2022/10/03 15:05:53 by jmeruma       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;

	if (lst == NULL)
		return (NULL);
	if (lst->next == NULL)
		return (lst);
	current = lst;
	while (current->next != NULL)
		current = current->next;
	return (current);
}
