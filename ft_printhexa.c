/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:43:12 by arahmoun          #+#    #+#             */
/*   Updated: 2022/11/07 20:43:14 by arahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexa(unsigned long n, const char *h)
{
	int	a;

	a = 0;
	if (n < 16)
	{
		ft_putchar(h[n]);
		a++;
	}
	else if (n >= 16)
	{
		a += ft_printhexa(n / 16, h);
		a += ft_printhexa(n % 16, h);
	}
	return (a);
}
