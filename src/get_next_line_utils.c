/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:33:35 by jopereir          #+#    #+#             */
/*   Updated: 2024/10/28 13:25:51 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	_size;
	size_t	i;
	void	*pnt;

	_size = size * nmemb;
	pnt = malloc(_size);
	if (!pnt)
		return (NULL);
	i = 0;
	while (i < _size)
		((unsigned char *)pnt)[i++] = '\0';
	return (pnt);
}

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str_return;
	int		length;
	int		i;
	int		j;

	length = ft_strlen(s1) + ft_strlen(s2) + 1;
	str_return = NULL;
	str_return = ft_calloc(length, sizeof(char));
	if (!str_return)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str_return[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		str_return[i++] = s2[j++];
	str_return[i] = 0;
	return (str_return);
}
