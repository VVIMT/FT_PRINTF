/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_type_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 23:34:15 by vinvimo           #+#    #+#             */
/*   Updated: 2017/06/24 05:00:11 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		var_4(const char *format, va_list *ap, t_types *t, int *ret)
{
	if (format[t->index] == 'X' && t->length == 0)
		*ret = get_x(t, va_arg(*ap, unsigned int), 1);
	else if (format[t->index] == 'X' && t->length == 3)
		*ret = get_x(t, va_arg(*ap, uintmax_t), 1);
	else if (format[t->index] == 'X' && t->length == 4)
		*ret = get_x(t, va_arg(*ap, size_t), 1);
	else if (format[t->index] == 'X' && t->length == 1)
		*ret = get_x(t, (unsigned short)va_arg(*ap, unsigned int), 1);
	else if (format[t->index] == 'X' && t->length == 11)
		*ret = get_x(t, (unsigned char)va_arg(*ap, unsigned int), 1);
	else if (format[t->index] == 'X' && t->length == 2)
		*ret = get_x(t, va_arg(*ap, unsigned long), 1);
	else if (format[t->index] == 'X' && t->length == 12)
		*ret = get_x(t, va_arg(*ap, unsigned long long), 1);
	else if ((format[t->index] == 'c'
			|| (format[t->index] == '%' && t->syntax > -1))
	&& t->length == 0)
		*ret = get_c(t, (char)va_arg(*ap, int), 0);
	else if (format[t->index] == 'C'
			|| (format[t->index] == 'c' && t->length == 2))
		*ret = get_c(t, va_arg(*ap, wint_t), 0);
	return (*ret);
}

int		var_5(const char *format, va_list *ap, t_types *t, int *ret)
{
	if (format[t->index] == 'b' && t->length == 0)
		*ret = get_b(t, va_arg(*ap, unsigned int));
	else if (format[t->index] == 'b' && t->length == 3)
		*ret = get_b(t, va_arg(*ap, uintmax_t));
	else if (format[t->index] == 'b' && t->length == 4)
		*ret = get_b(t, va_arg(*ap, size_t));
	else if (format[t->index] == 'b' && t->length == 1)
		*ret = get_b(t, (unsigned short)va_arg(*ap, unsigned int));
	else if (format[t->index] == 'b' && t->length == 11)
		*ret = get_b(t, (unsigned char)va_arg(*ap, unsigned int));
	else if (format[t->index] == 'b' && t->length == 2)
		*ret = get_b(t, va_arg(*ap, unsigned long));
	else if (format[t->index] == 'b' && t->length == 12)
		*ret = get_b(t, va_arg(*ap, unsigned long long));
	return (*ret);
}

int		var_6(const char *format, va_list *ap, t_types *t, int *ret)
{
	if (format[t->index] == 'p')
	{
		t->pointer = 1;
		t->sig4++;
		t->hex = va_arg(*ap, uintmax_t);
		if (t->hex)
			*ret = get_x(t, t->hex, 0);
		else
			*ret = get_x(t, 0, 0);
	}
	else if (format[t->index])
		*ret = get_c(t, format[t->index], 0);
	return (*ret);
}
