/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cho2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 09:57:18 by jperras           #+#    #+#             */
/*   Updated: 2022/03/02 13:00:03 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

void	ft_puthexa(unsigned long long b, int *i)
{
	if (b >= 16)
	{
		ft_puthexa(b / 16, i);
		ft_puthexa(b % 16, i);
	}
	else
	{
		if (b <= 9)
		{
			ft_putchar(b + '0');
			*i = *i + 1;
		}
		else
		{
			ft_putchar(b + 'W');
			*i = *i + 1;
		}
	}
}

void	ft_puthexaxx(unsigned int b, int *i)
{
	if (b >= 16)
	{
		ft_puthexa(b / 16, i);
		ft_puthexa(b % 16, i);
	}
	else
	{
		if (b <= 9)
		{
			ft_putchar(b + '0');
			*i = *i + 1;
		}
		else
		{
			ft_putchar(b + 'W');
			*i = *i + 1;
		}
	}
}

void	ft_puthexaxxmaj(unsigned int b, int *i)
{
	if (b >= 16)
	{
		ft_puthexaxxmaj(b / 16, i);
		ft_puthexaxxmaj(b % 16, i);
	}
	else
	{
		if (b <= 9)
		{
			ft_putchar(b + '0');
			*i = *i + 1;
		}
		else
		{
			ft_putchar(b + '7');
			*i = *i + 1;
		}
	}
}

void	ft_puthexax(va_list ap, int *i)
{
	unsigned int	j;

	j = va_arg(ap, unsigned int);
	ft_puthexaxx(j, i);
}

void	ft_puthexaxmaj(va_list ap, int *i)
{
	unsigned int	j;

	j = va_arg(ap, unsigned int);
	ft_puthexaxxmaj(j, i);
}
