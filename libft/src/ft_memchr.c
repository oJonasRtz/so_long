/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:14:32 by jopereir          #+#    #+#             */
/*   Updated: 2024/10/15 13:34:59 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Search for the first instance of 'c' in the first n Bytes of 's'
	
	Returns a pointer to 'c' in 's' or NULL
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*pnt;
	size_t			i;

	pnt = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (pnt[i] == (unsigned char)c)
			return ((void *)&pnt[i]);
		i++;
	}
	return (NULL);
}
