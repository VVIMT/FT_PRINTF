/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 00:00:52 by vinvimo           #+#    #+#             */
/*   Updated: 2017/06/20 00:00:54 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base_u(uintmax_t value, int base, int upper_case)
{
	uintmax_t	nb;
	uintmax_t	lvalue;
	t_types		t;

	lvalue = value;
	nb = lvalue;
	t.n = 0;
	while (nb > 0)
	{
		nb = nb / base;
		t.n++;
	}
	nb = t.n;
	if (!(t.str = (char*)malloc(sizeof(char) * nb)))
		return (NULL);
	while (nb + 1 > 0)
		t.str[nb--] = 0;
	if (value == 0)
	{
		t.str[0] = '0';
		return (t.str);
	}
	t.upper_case = upper_case;
	fill_tab(&t, lvalue, base);
	return (t.str);
}

void	fill_tab(t_types *t, uintmax_t lvalue, int base)
{
	t->n--;
	while (t->n >= 0 && lvalue > 0)
	{
		if (lvalue % base <= 9)
			t->str[t->n] = lvalue % base + '0';
		else if (lvalue % base > 9 && t->upper_case == 0)
			t->str[t->n] = lvalue % base - 10 + 'a';
		else if (lvalue % base > 9 && t->upper_case == 1)
			t->str[t->n] = lvalue % base - 10 + 'A';
		lvalue = lvalue / base;
		t->n--;
	}
}
