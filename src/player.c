/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:50:58 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/12 13:51:59 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_pressed(int key)
{
	if (key == 119 || key == 97 || key == 115 || key == 100)
		return (1);
	return (0);
}

void	move_player(t_data *data, int x_direction, int y_direction)
{
	int		new_x;
	int		new_y;
	char	next_tile;

	new_x = data->x + (x_direction * TILE);
	new_y = data->y + (y_direction * TILE);
	next_tile = data->map[new_y / TILE][new_x / TILE];
	if (next_tile == '1')
		return ;
	if (next_tile == 'C')
		data->collectables_cnt--;
	data->map[data->y / TILE][data->x / TILE] = '0';
	data->map[new_y / TILE][new_x / TILE] = 'P';
	render(data);
	data->moves++;
}
