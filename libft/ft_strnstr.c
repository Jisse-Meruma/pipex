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

static int	ft_scan(const char *haystack, const char *needle,
				size_t len, size_t i);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*ptr;
	size_t	j;

	i = 0;
	j = 0;
	ptr = (char *)haystack;
	if (needle[i] == '\0' || needle == haystack)
		return (ptr);
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[j])
		{
			if (ft_scan(haystack, needle, len, i) == 1)
				return (ptr + i);
		}
		i++;
	}
	return (0);
}

static int	ft_scan(const char *haystack, const char *needle,
					size_t len, size_t i)
{
	size_t	j;

	j = 0;
	while (haystack[i] == needle[j] && needle[j] && haystack[i])
	{
		i++;
		j++;
	}
	if (needle[j] == '\0' && i <= len)
		return (1);
	return (0);
}
