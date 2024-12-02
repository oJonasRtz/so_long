/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 10:37:41 by jopereir          #+#    #+#             */
/*   Updated: 2024/10/10 10:58:12 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	This function fills the first 'n' bytes of the string *s with the char 'c'
*/
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*pnt;

	pnt = (unsigned char *)s;
	while (n > 0)
	{
		pnt[n - 1] = c;
		n--;
	}
	return (s);
}
