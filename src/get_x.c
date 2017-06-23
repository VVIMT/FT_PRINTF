/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 00:02:17 by vinvimo           #+#    #+#             */
/*   Updated: 2017/06/22 21:05:52 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_x(t_types *t, uintmax_t hex, int upper_case)
{
	t->hex = hex;
	t->tmp = ft_itoa_base_u(hex, 16, upper_case);
	t->tmp[0] = (hex == 0 && t->precision == 0) ? 0 : t->tmp[0];
	t->x = ft_strlen(t->tmp);
	t->x = (t->precision >= 0 && t->precision > t->x) ? t->precision : t->x;
	t->start = (t->sig4 > 0 && (hex > 0 || t->pointer == 1)) ? 2 : 0;
	t->str = ft_strnew(t->x + t->start + 2);
	ft_memset(t->str, 0, t->x + t->start + 2);
	t->y = ft_strlen(t->tmp);
	while (--t->y >= 0)
		t->str[--t->x] = t->tmp[t->y];
	while (--t->x >= 0)
		t->str[t->x] = '0';
	free(t->tmp);
	t->x = ft_strlen(t->str) + t->start;
	if ((size_t)(t->width) > ft_strlen(t->str) + t->start)
		t->x = t->width;
	t->tmp = ft_strnew(t->x + 1);
	ft_bzero(t->tmp, t->x + 1);
	t->ret = t->x;
	flag_field_x(t, &upper_case);
	write(1, t->str, t->ret);
	free(t->str);
	return (t->ret);
}

void	push_right_x(t_types *t, int *upper_case)
{
	t->y = ft_strlen(t->str);
	while (--(t->y) >= 0)
		t->tmp[--t->x] = t->str[t->y];
	t->x = ft_strlen(t->tmp);
	if (t->sig4 > 0 && (t->hex > 0 || t->pointer == 1))
	{
		if (t->x >= 0)
			while (t->x > 1 && t->tmp[t->x] != ' ')
				t->x--;
		t->x--;
		t->tmp[t->x] = '0';
		t->tmp[t->x + 1] = 'x' - (*upper_case * 32);
	}
}

void	push_left_x(t_types *t, int *upper_case)
{
	t->x = 0;
	if (t->sig4 > 0
		&& ((t->str[0] != '0' && t->hex > 0) || t->pointer == 1))
	{
		t->tmp[0] = '0';
		t->tmp[1] = 'x' - (*upper_case * 32);
		t->x = t->x + 2;
	}
	t->y = 0;
	while (t->str[t->y])
		t->tmp[t->x++] = t->str[t->y++];
}

void	flag_field_x(t_types *t, int *upper_case)
{
	ft_memset(t->tmp, ' ', t->x);
	if (t->sig3 > 0 && t->sig2 == 0 && t->precision < 0)
		ft_memset(t->tmp, '0', t->x);
	if (t->sig2 == 0
		&& (t->hex != 0 || t->precision != 0 || t->pointer == 1))
		push_right_x(t, upper_case);
	else if (t->sig2 > 0
		&& (t->hex != 0 || t->precision != 0 || t->pointer == 1))
		push_left_x(t, upper_case);
	free(t->str);
	t->str = t->tmp;
}