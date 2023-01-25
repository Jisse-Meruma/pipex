/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:57:42 by jmeruma           #+#    #+#             */
/*   Updated: 2022/10/18 10:58:05 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	putstr_util(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i += putchar_util(s[i]);
	return (i);
}

int	putchar_util(char c)
{
	write(1, &c, 1);
	return (1);
}
