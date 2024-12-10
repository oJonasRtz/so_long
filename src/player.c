/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:50:58 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/10 15:53:02 by jopereir         ###   ########.fr       */
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
	int	move_speed;

	move_speed = TILE;
	data->map[data->x][data->y] = '0';
	data->x += x_direction * move_speed;
	data->y += y_direction * move_speed;
	data->map[data->y][data->x] = 'P';
	render(data);
}
