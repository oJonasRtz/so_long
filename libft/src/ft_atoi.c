/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:40:31 by jopereir          #+#    #+#             */
/*   Updated: 2024/10/15 13:59:18 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Takes a string (char *) and converts to int
*/
static int	is_space(char c)
{
	return (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v');
}

static int	is_sign(char c)
{
	return (c == '-' || c == '+');
}

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;
	int	i;

	i = 0;
	while (is_space(nptr[i]))
		i++;
	sign = 1;
	if (is_sign(nptr[i]))
	{
		if (nptr[i++] == '-' && sign == 1)
			sign = (-1);
	}
	result = 0;
	while (nptr[i] && ft_isdigit(nptr[i]))
		result = result * 10 + (nptr[i++] - '0');
	return (sign * result);
}
