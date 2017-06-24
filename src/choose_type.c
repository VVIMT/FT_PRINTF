/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 23:58:51 by vinvimo           #+#    #+#             */
/*   Updated: 2017/06/24 04:59:19 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		var_1(const char *format, va_list *ap, t_types *t, int *ret)
{
	if (format[t->index] == 's' && t->length == 0)
		*ret = get_s(t, va_arg(*ap, char *), 0);
	else if (format[t->index] == 'S'
		|| (format[t->index] == 's' && t->length == 2))
		*ret = get_upper_s(t, va_arg(*ap, wchar_t *));
	else if ((format[t->index] == 'd' || format[t->index] == 'i')
	&& t->length == 0)
		*ret = get_d(t, va_arg(*ap, int));
	else if ((format[t->index] == 'd' || format[t->index] == 'i')
	&& t->length == 3)
		*ret = get_d(t, va_arg(*ap, intmax_t));
	else if ((format[t->index] == 'd' || format[t->index] == 'i')
	&& t->length == 4)
		*ret = get_d(t, va_arg(*ap, size_t));
	else if ((format[t->index] == 'd' || format[t->index] == 'i')
		&& t->length == 1)
		*ret = get_d(t, (short)va_arg(*ap, int));
	else if (format[t->index] == 'D'
	|| ((format[t->index] == 'd' || format[t->index] == 'i') && t->length == 2))
		*ret = get_d(t, va_arg(*ap, long));
	else if ((format[t->index] == 'd' || format[t->index] == 'D'
		|| format[t->index] == 'i') && t->length == 12)
		*ret = get_d(t, va_arg(*ap, long long));
	return (*ret);
}

int		var_2(const char *format, va_list *ap, t_types *t, int *ret)
{
	if ((format[t->index] == 'd' || format[t->index] == 'i') && t->length == 11)
		*ret = get_d(t, (char)va_arg(*ap, int));
	else if (format[t->index] == 'u' && t->length == 0)
		*ret = get_u(t, va_arg(*ap, unsigned int));
	else if (format[t->index] == 'u' && t->length == 3)
		*ret = get_u(t, va_arg(*ap, uintmax_t));
	else if (format[t->index] == 'u' && t->length == 4)
		*ret = get_u(t, va_arg(*ap, size_t));
	else if (format[t->index] == 'u' && t->length == 1)
		*ret = get_u(t, (unsigned short)va_arg(*ap, unsigned int));
	else if (format[t->index] == 'u' && t->length == 11)
		*ret = get_u(t, (unsigned char)va_arg(*ap, unsigned int));
	else if (format[t->index] == 'U'
		|| (format[t->index] == 'u' && t->length == 2))
		*ret = get_u(t, va_arg(*ap, unsigned long));
	else if ((format[t->index] == 'U' || format[t->index] == 'u')
		&& t->length == 12)
		*ret = get_u(t, va_arg(*ap, unsigned long long));
	else if (format[t->index] == 'o' && t->length == 0)
		*ret = get_o(t, va_arg(*ap, unsigned int));
	else if (format[t->index] == 'o' && t->length == 3)
		*ret = get_o(t, va_arg(*ap, uintmax_t));
	else if (format[t->index] == 'o' && t->length == 4)
		*ret = get_o(t, va_arg(*ap, size_t));
	return (*ret);
}

int		var_3(const char *format, va_list *ap, t_types *t, int *ret)
{
	if (format[t->index] == 'o' && t->length == 1)
		*ret = get_o(t, (unsigned short)va_arg(*ap, unsigned int));
	else if (format[t->index] == 'o' && t->length == 11)
		*ret = get_o(t, (unsigned char)va_arg(*ap, unsigned int));
	else if (format[t->index] == 'O'
		|| (format[t->index] == 'o' && t->length == 2))
		*ret = get_o(t, va_arg(*ap, unsigned long));
	else if ((format[t->index] == 'O' || format[t->index] == 'o')
		&& t->length == 12)
		*ret = get_o(t, va_arg(*ap, unsigned long long));
	else if (format[t->index] == 'x' && t->length == 0)
		*ret = get_x(t, va_arg(*ap, unsigned int), 0);
	else if (format[t->index] == 'x' && t->length == 3)
		*ret = get_x(t, va_arg(*ap, uintmax_t), 0);
	else if (format[t->index] == 'x' && t->length == 4)
		*ret = get_x(t, va_arg(*ap, size_t), 0);
	else if (format[t->index] == 'x' && t->length == 1)
		*ret = get_x(t, (unsigned short)va_arg(*ap, unsigned int), 0);
	else if (format[t->index] == 'x' && t->length == 11)
		*ret = get_x(t, (unsigned char)va_arg(*ap, unsigned int), 0);
	else if (format[t->index] == 'x' && t->length == 2)
		*ret = get_x(t, va_arg(*ap, unsigned long), 0);
	else if (format[t->index] == 'x' && t->length == 12)
		*ret = get_x(t, va_arg(*ap, unsigned long long), 0);
	return (*ret);
}
