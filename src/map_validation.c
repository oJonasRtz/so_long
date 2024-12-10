/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:24:22 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/10 13:04:03 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_rectangular(char **map)
{
	int	i;

	i = 1;
	while (map[i])
	{
		if (ft_strlen_char(map[i], '\n') != ft_strlen_char(map[i - 1], '\n'))
			return (0);
		i++;
	}
	return (1);
}

int	map_is_valid(char **map)
{
	if (!is_rectangular(map))
		return (0);
	return (1);
}
