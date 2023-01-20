/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basetoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 09:42:13 by jmeruma           #+#    #+#             */
/*   Updated: 2022/10/24 11:34:35 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	checks(unsigned long nb);
char		*strcreation(unsigned long nb, int base);

int	basetoa(const char *baseset, int base, unsigned long nb)
{
	char	*ptr;
	int		set;
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	if (checks(nb) == 1)
		return (1);
	ptr = strcreation(nb, base);
	if (!ptr)
		return (0);
	while (nb != 0)
	{
		set = nb % base;
		ptr[i] = baseset[set];
		nb /= base;
		i++;
	}
	while (--i >= 0)
		counter += putchar_util(ptr[i]);
	free(ptr);
	return (counter);
}

static int	checks(unsigned long nb)
{
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	return (0);
}

char	*strcreation(unsigned long nb, int base)
{
	int		len;
	char	*ptr;

	len = 0;
	while (nb != 0)
	{
		nb /= base;
		len++;
	}
	len++;
	ptr = malloc(len + 1 * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	return (ptr);
}
