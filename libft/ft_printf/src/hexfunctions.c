/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexfunctions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:39:30 by jmeruma           #+#    #+#             */
/*   Updated: 2022/10/24 09:55:56 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	printf_hexlow(va_list arglist)
{
	unsigned int	nb;
	int				len;

	len = 0;
	nb = va_arg(arglist, unsigned int);
	len += basetoa("0123456789abcdef", 16, nb);
	return (len);
}

int	printf_hexup(va_list arglist)
{
	unsigned int	nb;
	int				len;

	len = 0;
	nb = va_arg(arglist, unsigned int);
	len += basetoa("0123456789ABCDEF", 16, nb);
	return (len);
}

int	printf_hexpoint(va_list arglist)
{
	unsigned long		nb;
	int					len;

	len = 2;
	nb = va_arg(arglist, unsigned long);
	write(1, "0x", 2);
	len += basetoa("0123456789abcdef", 16, nb);
	return (len);
}
