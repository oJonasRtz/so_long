/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:45:33 by jopereir          #+#    #+#             */
/*   Updated: 2024/10/18 09:47:08 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Takes a int number and converts to a string

	num_count counts the minus signal '-'
*/
static int	num_count(int n)
{
	int	cnt;

	cnt = 1;
	if (n < 0)
	{
		n = -n;
		cnt++;
	}
	while (n >= 10)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

static void	convertion(int n, char *str, int nb_count)
{
	int	i;

	i = nb_count - 1;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	if (n == 0)
		str[i] = '0';
	while (n > 0)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		nb_count;
	int		i;

	nb_count = num_count(n);
	str = (char *)malloc(sizeof(char) * (nb_count + 1));
	if (!str)
		return (NULL);
	str[nb_count] = '\0';
	i = 0;
	if (n == (-2147483648LL))
		ft_strlcpy(str, "-2147483648", 12);
	else
		convertion(n, str, nb_count);
	return (str);
}
