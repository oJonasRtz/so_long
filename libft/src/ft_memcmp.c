/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:14:29 by jopereir          #+#    #+#             */
/*   Updated: 2024/10/14 13:44:23 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Compares if n bytes of the memory are equal

	returns 0 if there equal
	returns the diference between then if there's a diference
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*pnt1;
	unsigned char	*pnt2;

	i = 0;
	pnt1 = (unsigned char *)s1;
	pnt2 = (unsigned char *)s2;
	while (i < n)
	{
		if (pnt1[i] != pnt2[i])
			return (pnt1[i] - pnt2[i]);
		i++;
	}
	return (0);
}
