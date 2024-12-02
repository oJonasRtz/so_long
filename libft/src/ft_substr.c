/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:11:42 by jopereir          #+#    #+#             */
/*   Updated: 2024/10/15 15:02:12 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Makes a substring

	the substring starts at 'start' to 'len'
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		j;
	char		*substr;

	substr = NULL;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	i = start;
	j = 0;
	while (i < (size_t)ft_strlen(s) && j < len)
		substr[j++] = s[i++];
	substr[j] = '\0';
	return (substr);
}
