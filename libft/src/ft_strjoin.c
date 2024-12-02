/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:11:51 by jopereir          #+#    #+#             */
/*   Updated: 2024/10/17 12:58:57 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Alocate with malloc and return a string concatenate of s1 and s2
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_return;
	int		length;

	length = ft_strlen(s1) + ft_strlen(s2) + 1;
	str_return = NULL;
	str_return = malloc(sizeof(char) * length);
	if (!str_return)
		return (NULL);
	ft_strlcpy(str_return, s1, ft_strlen(s1) + 1);
	ft_strlcat(str_return, s2, length);
	return (str_return);
}
