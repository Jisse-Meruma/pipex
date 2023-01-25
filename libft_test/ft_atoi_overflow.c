/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_overflow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:05:51 by jmeruma           #+#    #+#             */
/*   Updated: 2023/01/20 18:17:46 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>

int	ft_atoi_overflow(const char *str, int *numb)
{
	int	i;
	int	sign;

	i = 0;
	*numb = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
			i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		*numb += str[i] - '0';
		if (str[i + 1] >= '0' && str[i + 1] <= '9')
			*numb *= 10;
		if (*numb < 0 && (*numb != INT_MIN || sign == 1))
			return (1);
		i++;
	}
	*numb *= sign;
	return (0);
}
