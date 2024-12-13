/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:50:58 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/13 10:54:24 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_true(int operation)
{
	return (operation);
}

t_keys	get_keys(int key)
{
	t_keys	keys;

	keys.right = ft_true(key == 100 || key == 65363);
	keys.left = ft_true(key == 97 || key == 65361);
	keys.up = ft_true(key == 119 || key == 65362);
	keys.down = ft_true(key == 115 || key == 65364);
	return (keys);
}

int	key_pressed(int key)
{
	if (key == 119 || key == 97 || key == 115 || key == 100
		|| key == 65361 || key == 65362 || key == 65363 || key == 65364)
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
	if (next_tile == 'E')
	{
		if (data->collectables_cnt == 0)
			game_destroy(data, "Contratulations, you won the game!!!");
		else
			return ;
	}
	data->map[data->y / TILE][data->x / TILE] = '0';
	data->map[new_y / TILE][new_x / TILE] = 'P';
	render(data);
	data->moves++;
}
