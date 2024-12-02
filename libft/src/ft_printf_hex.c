/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:34:18 by jopereir          #+#    #+#             */
/*   Updated: 2024/11/01 10:11:59 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_count_base(unsigned long n, unsigned long base_len)
{
	int	cnt;

	cnt = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base_len;
		cnt++;
	}
	return (cnt);
}

/*
	Takes a int and converts to a base
*/
int	ft_itoa_base(unsigned long value, char *base)
{
	int					len;
	char				*temp;
	unsigned int		base_len;

	if (value == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	base_len = ft_strlen(base);
	len = ft_num_count_base(value, base_len);
	temp = ft_calloc(len + 1, sizeof(char));
	if (!temp)
		return (0);
	while (value > 0 && len > 0)
	{
		temp[--len] = base[value % base_len];
		value /= base_len;
	}
	ft_putstr_fd(temp, 1);
	len = ft_strlen(temp);
	free(temp);
	return (len);
}

unsigned long	ft_get_pointer(unsigned long p)
{
	unsigned long	len;
	unsigned long	pnt;

	if (!p)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	pnt = p;
	ft_putstr_fd("0x", 1);
	len = ft_itoa_base(pnt, "0123456789abcdef");
	return (len + 2);
}
