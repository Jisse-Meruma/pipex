/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:53:56 by jmeruma           #+#    #+#             */
/*   Updated: 2023/01/20 18:17:52 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *nb)
{
	int		i;
	int		x;
	long	numb;

	i = 0;
	x = 1;
	numb = 0;
	while (nb[i] == ' ' || nb[i] == '\f' || nb[i] == '\n'
		|| nb[i] == '\r' || nb[i] == '\t' || nb[i] == '\v')
			i++;
	if (nb[i] == '-')
		x = -1;
	if (nb[i] == '+' || nb[i] == '-')
		i++;
	while (nb[i] >= '0' && nb[i] <= '9')
	{
		numb += nb[i] - '0';
		if (nb[i + 1] >= '0' && nb[i + 1] <= '9')
			numb *= 10;
		i++;
	}
	numb *= x;
	return (numb);
}
