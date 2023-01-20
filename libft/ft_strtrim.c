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
#include <stdio.h>

static int	begin(char const *s1, char const *set, int total_set);
static int	end(char const *s1, char const *set, int total_s1, int total_set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		skip1;
	int		skip2;

	skip1 = begin(s1, set, ft_strlen(set));
	skip2 = end(s1, set, ft_strlen(s1), ft_strlen(set));
	if (skip1 == ft_strlen(s1))
	{
		ptr = ft_strdup("");
		if (!ptr)
			return (NULL);
		return (ptr);
	}
	ptr = (char *)ft_calloc((skip2 - skip1) + 1, 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, (char *)s1 + skip1, (skip2 - skip1) + 1);
	return (ptr);
}

static int	begin(char const *s1, char const *set, int total_set)
{
	int		i;
	char	*p;

	i = 0;
	while (s1[i])
	{
		p = (char *)ft_memchr(set, s1[i], total_set);
		if (!p)
			break ;
		i++;
	}
	return (i);
}

static int	end(char const *s1, char const *set, int total_s1, int total_set)
{
	int		i;
	char	*p;

	i = total_s1 - 1;
	while (total_s1 > 0)
	{
		p = (char *)ft_memchr(set, s1[i], total_set);
		if (!p)
			break ;
		i--;
	}
	return (i + 1);
}
