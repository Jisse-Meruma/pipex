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

static char	*creation(char const *s, unsigned int start, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	i = ft_strlen(s);
	if (i < start)
		return (ft_strdup(""));
	ptr = creation(s, start, len);
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static char	*creation(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	i = 0;
	while (s[start] && i < len)
	{
		start++;
		i++;
	}
	ptr = (char *)malloc(i + 1);
	return (ptr);
}
