/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 08:14:35 by jperras           #+#    #+#             */
/*   Updated: 2022/03/02 14:25:30 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/ft_printf.h"

t_cho		g_choose[] = {['s'] = ft_string, ['c'] = ft_char,
['d'] = ft_putnbr, ['i'] = ft_putnbr,
['u'] = ft_absputnbr, ['p'] = ft_putadr,
['x'] = ft_puthexax, ['X'] = ft_puthexaxmaj};

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		a;
	int		b;
	int		*i;
	int		*j;

	i = &a;
	*i = 0;
	j = &b;
	*j = 0;
	va_start(ap, format);
	while (format[*j] != '\0')
	{
		ft_read(format + *j, i, j);
		if ((format[*j] == '%' && (format[*j + 1] >= 'a'
					&& format[*j + 1] <= 'z' )) || format[*j + 1] == 'X')
		{
			g_choose[(int)format[*j + 1]](ap, i);
			*j = *j + 2;
		}
	}
	va_end(ap);
	return (*i);
}
