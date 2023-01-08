/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:40:31 by arahmoun          #+#    #+#             */
/*   Updated: 2022/11/07 20:40:34 by arahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *str)
{
	int	a;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	a = ft_strlen(str);
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
	return (a);
}
