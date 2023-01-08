/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:45:00 by arahmoun          #+#    #+#             */
/*   Updated: 2022/11/19 16:34:14 by arahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_put(va_list ptr, const char *str, int i)
{
	int	a;

	a = 0;
	if (str[i] == '%' && str[i + 1] == '%')
		a += ft_putchar('%');
	else if (str[i] == '%' && str[i + 1] == 's')
		a += ft_putstr(va_arg(ptr, char *));
	else if (str[i] == '%' && str[i + 1] == 'c')
		a += ft_putchar((char)va_arg(ptr, int));
	else if (str[i] == '%' && str[i + 1] == 'i')
		a += ft_putnbr(va_arg(ptr, int));
	else if (str[i] == '%' && str[i + 1] == 'd')
		a += ft_putnbr(va_arg(ptr, int));
	else if (str[i] == '%' && str[i + 1] == 'u')
		a += ft_putunsigned(va_arg(ptr, unsigned long));
	else if (str[i] == '%' && str[i + 1] == 'x')
		a += ft_printhexa(va_arg(ptr, unsigned int), "0123456789abcdef");
	else if (str[i] == '%' && str[i + 1] == 'X')
		a += ft_printhexa(va_arg(ptr, unsigned int), "0123456789ABCDEF");
	return (a);
}

int	ft_putit(va_list ptr, const char *str)
{
	int	a;
	int	i;

	a = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i] == '%') && (str[i + 1] == '%' || str[i + 1] == 's'
				|| str[i + 1] == 'x' || str[i + 1] == 'c'
				|| str[i + 1] == 'X' || str[i + 1] == 'u'
				|| str[i + 1] == 'd' || str[i + 1] == 'i'))
			a += ft_put(ptr, str, i);
		else if (str[i] == '%' && str[i + 1] == 'p')
		{
			a += ft_putstr("0x");
			a += ft_printhexa(va_arg(ptr, unsigned long), "0123456789abcdef");
		}
		else if (str[i] == '%' && str[++i] != '%')
			continue ;
		else
			a += ft_putchar(str[i--]);
		i += 2;
	}
	return (a);
}

int	ft_printf(const char *str, ...)
{
	int		b;
	va_list	ptr;

	va_start(ptr, str);
	b = ft_putit(ptr, str);
	va_end(ptr);
	return (b);
}
