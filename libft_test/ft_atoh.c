/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:24:49 by jmeruma           #+#    #+#             */
/*   Updated: 2023/01/10 11:16:52 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

unsigned int	ft_atohex(const char *hex)
{
	int				i;
	unsigned int	numb;

	i = 0;
	numb = 0;
	while (hex[i] == ' ' || hex[i] == '\f' || hex[i] == '\n'
		|| hex[i] == '\r' || hex[i] == '\t' || hex[i] == '\v')
			i++;
	while (ft_isalnum(hex[i]) == 1 || hex[i] == '\n')
	{
		if (hex[i] >= '0' && hex[i] <= '9')
			numb += hex[i] - '0';
		else if (hex[i] >= 'a' && hex[i] <= 'z')
			numb += hex[i] - 'W';
		else if (hex[i] >= 'A' && hex[i] <= 'Z')
			numb += hex[i] - '7';
		if (ft_isalnum(hex[i + 1]) == 1)
			numb *= 16;
		i++;
	}
	return (numb);
}
