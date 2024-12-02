/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:36:36 by jopereir          #+#    #+#             */
/*   Updated: 2024/10/10 11:04:45 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	This function returns a pointer to a duplate of string 's'

	Memory is allocated with malloc and must be freed(free(duplicate)) 
	to prevent memory leak
*/
char	*ft_strdup(const char *s)
{
	char	*duplicate;
	int		i;

	duplicate = NULL;
	duplicate = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!duplicate)
		return (NULL);
	i = 0;
	while (s[i])
	{
		duplicate[i] = s[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}
