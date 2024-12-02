/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:41:07 by jopereir          #+#    #+#             */
/*   Updated: 2024/10/23 12:51:33 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Alocates memory

	and fill all the slots with '\0'

	h = ft_calloc(10, sizeof(char));
*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	_size;
	void	*pnt;

	_size = size * nmemb;
	pnt = malloc(_size);
	if (!pnt)
		return (NULL);
	ft_bzero(pnt, _size);
	return (pnt);
}
