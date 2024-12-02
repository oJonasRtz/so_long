/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:11:45 by jopereir          #+#    #+#             */
/*   Updated: 2024/10/17 10:57:35 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Makes a copy of s1 and return the string without set char

	ex: "test", "t" returns "es"
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*copy;
	int		start;
	int		end;
	int		length;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	length = end - start + 1;
	copy = malloc(length + 1);
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, &s1[start], length + 1);
	return (copy);
}
