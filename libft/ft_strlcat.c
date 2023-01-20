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

int	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	sum;

	j = 0;
	i = 0;
	while (src[i] != '\0')
		i++;
	while (dest[j] != '\0' && j < dstsize)
		j++;
	sum = i + j;
	i = 0;
	if (dstsize > j)
	{
		while (src[i] != '\0' && j < (dstsize - 1))
		{
			dest[j] = src[i];
			i++;
			j++;
		}
		if (dstsize > 2)
			dest[j] = '\0';
	}
	return (sum);
}
