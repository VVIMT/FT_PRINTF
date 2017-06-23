/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode_to_utf8.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 00:02:43 by vinvimo           #+#    #+#             */
/*   Updated: 2017/06/20 00:02:46 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t	*unicode_to_utf8(wchar_t c, wchar_t *b, int *i)
{
	static wchar_t	b_static[5];

	b = b_static;
	if (c < (1 << 7))
		*b++ = (wchar_t)(c);
	else if (c < (1 << 11))
	{
		*b++ = (wchar_t)((c >> 6) | 0xC0);
		*b++ = (wchar_t)((c & 0x3F) | 0x80);
	}
	else if (c < (1 << 16))
	{
		*b++ = (wchar_t)(((c >> 12)) | 0xE0);
		*b++ = (wchar_t)(((c >> 6) & 0x3F) | 0x80);
		*b++ = (wchar_t)((c & 0x3F) | 0x80);
	}
	else if (c < (1 << 21))
	{
		*b++ = (wchar_t)(((c >> 18)) | 0xF0);
		*b++ = (wchar_t)(((c >> 12) & 0x3F) | 0x80);
		*b++ = (wchar_t)(((c >> 6) & 0x3F) | 0x80);
		*b++ = (wchar_t)((c & 0x3F) | 0x80);
	}
	wchar_length(b, i, b_static);
	return (b_static);
}

void	wchar_length(wchar_t *b, int *i, wchar_t *b_static)
{
	*b = '\0';
	*i = *i + b - b_static;
}
