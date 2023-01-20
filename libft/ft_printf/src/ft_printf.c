/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:41:25 by jmeruma           #+#    #+#             */
/*   Updated: 2022/10/24 11:23:27 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static const t_func	g_function_list[128] = {
['c'] = &printf_putchar,
['s'] = &printf_putstr,
['p'] = &printf_hexpoint,
['d'] = &printf_putnbr,
['i'] = &printf_putnbr,
['u'] = &printf_unputnbr,
['x'] = &printf_hexlow,
['X'] = &printf_hexup,
['%'] = &printf_putprecent
};

int	ft_printf(char const *format, ...)
{
	int		i;
	int		len;
	va_list	arglist;

	va_start(arglist, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{		
			i++;
			if (g_function_list[(int)format[i]] != NULL)
				len += (*g_function_list[(int)format[i]])(arglist);
		}
		else if (format[i] != '%')
			len += putchar_util(format[i]);
		i++;
	}
	va_end(arglist);
	return (len);
}

int	printf_putprecent(va_list arglist)
{
	(void) arglist;
	write(1, "%", 1);
	return (1);
}
