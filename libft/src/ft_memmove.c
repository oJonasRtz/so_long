/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:14:38 by jopereir          #+#    #+#             */
/*   Updated: 2024/10/14 14:50:38 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	It does the same as memcpy but handles memory overlap
	(when two variables use the same address at the same time).

	When src is greater than dest, there is no overlap, so you can use memcpy().
	Otherwise, you should write from back to front to copy correctly.

	literal variables can only be read
		ex: h = "abcdefg";
	it must be declared as the main bellow
		or like this
				char	h[10];
				char	*w;

				ft_strlcpy(h, "abcdefgh", 10);
				w = h + 2;
				ft_memmove(w, h, 9);
				printf("Verificação: %s\n", w);

	Main to test
	
#include "libft.h"
#include <stdio.h>

int	main(void)
{
	char	h[] = "abcdefgh";
	char	*w = h + 2;

	h = "lalala"
	ft_memmove(w, h, 9);
	printf("Verificação: %s\n", w);
}
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (src > dest)
		return (ft_memcpy(dest, src, n));
	else
	{
		while (n--)
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	}
	return (dest);
}
