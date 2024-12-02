/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:46:46 by jopereir          #+#    #+#             */
/*   Updated: 2024/11/01 10:11:53 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_count_unsigned(unsigned int n)
{
	int	cnt;

	cnt = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

/*
	Displays a unsigned int
*/
void	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	char	c;

	if (n >= 10)
		ft_putnbr_unsigned_fd(n / 10, fd);
	c = '0' + (n % 10);
	write(fd, &c, 1);
}

/*
	displays a unsigned int
*/
int	ft_get_unsigned(unsigned int n)
{
	int	len;

	len = ft_num_count_unsigned(n);
	ft_putnbr_unsigned_fd(n, 1);
	return (len);
}

/*
	Displays a int number
*/
int	ft_get_int(int n)
{
	int	num_cunt;

	num_cunt = ft_num_count(n);
	if (n < 0)
		num_cunt++;
	ft_putnbr_fd(n, 1);
	return (num_cunt);
}
