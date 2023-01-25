/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:41:07 by jmeruma           #+#    #+#             */
/*   Updated: 2022/10/21 14:53:33 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	printf_putchar(va_list arglist)
{
	char	c;
	int		i;

	c = va_arg(arglist, int);
	i = putchar_util(c);
	return (i);
}

int	printf_putstr(va_list arglist)
{
	char	*s;
	int		i;

	i = 0;
	s = va_arg(arglist, char *);
	if (!s)
		return (putstr_util("(null)"));
	i = putstr_util(s);
	return (i);
}

int	printf_putnbr(va_list arglist)
{
	long			nb;
	signed int		len;

	len = 0;
	nb = va_arg(arglist, signed int);
	if (nb < 0)
	{
		nb *= -1;
		len += putchar_util('-');
	}
	len += basetoa("0123456789", 10, nb);
	return (len);
}

int	printf_unputnbr(va_list arglist)
{
	unsigned int	nb;

	nb = va_arg(arglist, unsigned int);
	nb = basetoa("0123456789", 10, nb);
	return (nb);
}
