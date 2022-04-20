/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_useprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 09:47:30 by jperras           #+#    #+#             */
/*   Updated: 2022/03/02 12:43:21 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_read(const char *format, int *i, int *j)
{
	while ((*format != '%' && *format != '\0'))
	{
		ft_putchar(*format++);
		*i = *i + 1;
		*j = *j + 1;
	}
	if (*format == '%' && *(format + 1) == '%')
	{
		ft_putchar(*format++);
		*i = *i + 1;
		*j = *j + 2;
	}
}

void	ft_readnbr(int nb, int *j)
{
	unsigned int	i;

	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
		*j = *j + 1;
	}
	i = nb;
	if (i > 9)
	{
		ft_readnbr(i / 10, j);
		ft_readnbr(i % 10, j);
	}
	else
	{
		ft_putchar(i + '0');
		*j = *j + 1;
	}
}

void	ft_readabsnbr(unsigned int nb, int *j)
{
	if (nb > 9)
	{
		ft_readnbr(nb / 10, j);
		ft_readnbr(nb % 10, j);
	}
	else
	{
		ft_putchar(nb + '0');
		*j = *j + 1;
	}
}
