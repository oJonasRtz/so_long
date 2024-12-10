/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:48:32 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/10 15:50:22 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_no_event(void)
{
	return (0);
}

int	handle_input(int keysym, t_data *data)
{
	int	right;
	int	left;
	int	up;
	int	down;

	right = key_pressed(keysym == 100);
	left = key_pressed(keysym == 97);
	up = key_pressed(keysym == 119);
	down = key_pressed(keysym == 115);
	if (keysym == 65307)
		game_destroy(data);
	if (key_pressed(keysym))
		move_player(data, right - left, up - down);
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
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		return (ft_printf("Too few argumments.\n"));
	init_values(&data);
	if (!game_create(&data, argv[1]))
	{
		game_destroy(&data);
		exit(1);
	}
	if (data.mlx_ptr)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
	}
	ft_printf("Game successfully closed!\n\n");
	return (0);
}
