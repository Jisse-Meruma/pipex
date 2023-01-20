/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisse <jisse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:05:51 by jmeruma           #+#    #+#             */
/*   Updated: 2022/12/08 14:14:51 by jisse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

static int	lenght(int n);
static void	calc(char *ptr, int n, int sign, int counter);
static char	*checkmin(void);

char	*ft_itoa(int n)
{
	char	*ptr;
	int		counter;
	int		sign;

	sign = 1;
	if (n < 0)
	{
		sign = -1;
		n *= sign;
	}
	if (n == -2147483648)
	{
		ptr = checkmin();
		return (ptr);
	}
	counter = lenght(n);
	if (sign == -1)
		counter++;
	ptr = ft_calloc(counter + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	calc(ptr, n, sign, counter);
	return (ptr);
}

static int	lenght(int n)
{
	int		counter;

	counter = 1;
	while (n >= 10)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

static void	calc(char *ptr, int n, int sign, int counter)
{
	if (sign == -1)
		ptr[0] = '-';
	ptr[counter] = '\0';
	counter--;
	while (counter >= 0 && ptr[counter] != '-')
	{
		ptr[counter] = n % 10 + '0';
		n /= 10;
		counter--;
	}
}

static char	*checkmin(void)
{
	char	*ptr;

	ptr = ft_strdup("-2147483648");
	return (ptr);
}
