/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:48:32 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/13 11:41:18 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_no_event(t_data *data)
{
	data->icnt++;
	if (data->icnt >= data->update)
	{
		ft_printf("Screen_x: %d Screen_y: %d\n",
			data->screen_width, data->screen_height);
		ft_printf("Hight: %d Width: %d\n", data->win_height, data->win_width);
		ft_printf("Collectables: %d\n", data->collectables_cnt);
		ft_printf("Player X: %d\nPlayer Y: %d\n", data->x, data->y);
		ft_printf("Moves: %d\n", data->moves);
		data->icnt = 0;
	}
	return (0);
}

int	handle_input(int keysym, t_data *data)
{
	t_keys	keys;

	if (keysym == 65307)
		game_destroy(data, "Game closed by the player.");
	if (key_pressed(keysym))
	{
		keys = get_keys(keysym);
		move_player(data, keys.right - keys.left, keys.down - keys.up);
	}
	return (0);
}

void	init_values(t_data *data)
{
	data->mlx_ptr = NULL;
	data->collectables_cnt = 0;
	data->fd = 0;
	data->collectables = NULL;
	data->player = NULL;
	data->wall = NULL;
	data->ground = NULL;
	data->enemy = NULL;
	data->exit = NULL;
	data->lines = 0;
	data->map = NULL;
	data->map_height = 0;
	data->map_width = 0;
	data->win_ptr = NULL;
	data->win_height = 0;
	data->win_width = 0;
	data->x = 0;
	data->y = 0;
	data->icnt = 0;
	data->update = 2000;
	data->moves = 0;
	data->message = "!";
	data->screen_height = 0;
	data->screen_width = 0;
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		return (ft_printf("Error: Invalid number of arguments.\n"));
	if (TILE != 64)
		return (ft_printf("Error: Tile doesn't match.\n"));
	init_values(&data);
	if (!game_create(&data, argv[1]))
		game_destroy(&data, "Coundn't initialize the game.");
	return (0);
}
