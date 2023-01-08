/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:40:06 by arahmoun          #+#    #+#             */
/*   Updated: 2022/11/07 20:40:09 by arahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	int	a;

	a = 0;
	if (n <= 9 && n >= 0)
	{
		ft_putchar(n + '0');
		a++;
	}
	else
	{
		a += ft_putunsigned(n / 10);
		a += ft_putunsigned(n % 10);
	}
	return (a);
}
