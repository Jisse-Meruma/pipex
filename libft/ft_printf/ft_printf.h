/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:48:49 by jmeruma           #+#    #+#             */
/*   Updated: 2022/10/18 13:42:17 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef int		(*t_func) (va_list);

int				ft_printf(char const *format, ...);

int				printf_putchar(va_list arglist);
int				printf_putstr(va_list arglist);
int				printf_putnbr(va_list arglist);
int				printf_unputnbr(va_list arglist);
int				printf_hexlow(va_list arglist);
int				printf_hexup(va_list arglist);
int				printf_hexpoint(va_list arglist);
int				printf_putprecent(va_list arglist);

int				putstr_util(const char *s);
int				putchar_util(char c);
int				basetoa(const char *baseset, int base, unsigned long nb);

#endif