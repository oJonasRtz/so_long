/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:24:22 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/12 13:38:18 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_rectangular(t_data *data)
{
	int	i;
	int	len;

	i = 1;
	len = ft_strlen_char(data->map[0], '\n');
	while (data->map[i])
	{
		if (ft_strlen_char(data->map[i], '\n') != len)
			return (0);
		i++;
	}
	return (1);
}

static int	verify_requirements(int playes, int exit, int collectables)
{
	if (playes != 1 || exit != 1 || collectables == 0)
		return (0);
	return (1);
}

static int	minimun_requirements(t_data *data)
{
	int	i;
	int	j;
	int	players;
	int	exit;

	i = 0;
	players = 0;
	exit = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
				players++;
			if (data->map[i][j] == 'C')
				data->collectables_cnt++;
			if (data->map[i][j] == 'E')
				exit++;
			j++;
		}
		i++;
	}
	return (verify_requirements(players, exit, data->collectables_cnt));
}

static int	verify_walls(t_data *data)
{
	int	i;

	if (!is_all_one(data->map[0]) || !is_all_one(data->map[data->lines - 1]))
		return (0);
	i = 1;
	while (data->map[i + 1] != NULL)
		if (!first_and_last_is_one(data->map[i++]))
			return (0);
	return (1);
}

int	map_is_valid(t_data *data)
{
	if (!is_rectangular(data) || !minimun_requirements(data)
		|| !verify_walls(data))
		return (0);
	return (1);
}
