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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total;
	char	*ptr;

	total = ft_strlen(s1) + ft_strlen(s2);
	ptr = (char *)malloc(total + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, (char *)s1, (ft_strlen(s1) + 1));
	ft_strlcat(ptr, (char *)s2, (total + 1));
	return (ptr);
}
