/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 00:01:09 by vinvimo           #+#    #+#             */
/*   Updated: 2017/06/24 09:26:32 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <inttypes.h>
# include <wchar.h>

typedef struct	s_types
{
	int			ret;
	size_t		count;
	int			pointer;
	int			sig1;
	int			sig2;
	int			sig3;
	int			sig4;
	int			sig5;
	int			syntax;
	int			param;
	int			width;
	int			precision;
	int			length;
	int			start;
	long		index;
	int			upper_case;
	int			mem;
	int			n;
	long		x;
	long		y;
	char		c;
	intmax_t	d;
	uintmax_t	u;
	uintmax_t	oct;
	uintmax_t	hex;
	uintmax_t	bin;
	wchar_t		*upper_s;
	char		*dst;
	wchar_t		*upper_dst;
	char		*str;
	char		*tmp;
}				t_types;

void			initialize(t_types *t);
int				ft_printf(const char *format, ...);
size_t			get_param(const char *format, va_list *ap2, t_types *t);
void			get_flag(const char *format, t_types *t);
size_t			get_width(const char *format, t_types *t);
int				get_precision(const char *format, t_types *t, long precision);
size_t			get_length(const char *format, t_types *t);
int				var_1(const char *format, va_list *ap, t_types *t, int *ret);
int				var_2(const char *format, va_list *ap, t_types *t, int *ret);
int				var_3(const char *format, va_list *ap, t_types *t, int *ret);
int				var_4(const char *format, va_list *ap, t_types *t, int *ret);
int				var_5(const char *format, va_list *ap, t_types *t, int *ret);
int				var_6(const char *format, va_list *ap, t_types *t, int *ret);
int				get_d(t_types *t, intmax_t d);
void			flag_field_d(t_types *t);
int				get_u(t_types *t, uintmax_t u);
void			flag_field_u(t_types *t);
int				get_o(t_types *t, uintmax_t oct);
void			flag_field_o(t_types *t);
int				get_b(t_types *t, uintmax_t bin);
void			flag_field_b(t_types *t);
int				get_x(t_types *t, uintmax_t hex, int upper_case);
void			flag_field_x(t_types *t, int *upper_case);
int				get_s(t_types *t, char *s, int esc);
int				prepare_tab(t_types *t, char *s, int esc);
int				get_upper_s(t_types *t, wchar_t *s);
void			tab_upper_s(t_types *t, wchar_t *s, int *i, int *j);
int				get_c(t_types *t, wchar_t c, int i);
void			c_in_tab(t_types *t, wchar_t c, int *i);
char			*ft_itoa_base_u(uintmax_t value, int base, int upper_case);
void			fill_tab(t_types *t, uintmax_t lvalue, int base);
wchar_t			*unicode_to_utf8(wchar_t c, wchar_t *b, int *i);
void			wchar_length(wchar_t *b, int *i, wchar_t *b_static);

#endif
