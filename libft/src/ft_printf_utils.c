/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:24:24 by jopereir          #+#    #+#             */
/*   Updated: 2024/11/01 10:11:48 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	counts the amount of numbers of a int
*/
int	ft_num_count(int n)
{
	int	cnt;

	cnt = 1;
	if (n == 0)
		return (cnt);
	if (n == (-2147483648))
		return (10);
	if (n < 0)
		n = -n;
	if (n >= 10)
		cnt += ft_num_count(n / 10);
	return (cnt);
}
