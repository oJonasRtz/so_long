/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:21:39 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/03 14:29:20 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	starts the game. First events to run
*/
int	game_create(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			data->map_width, data->map_height, "so_long");
	game_step(data);
	return (0);
}

/*
	runs the game. Frame per frame

	mlx_hook - calls game_destroy when click on window's 'x'
*/
int	game_step(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, &handle_no_event, data);
	mlx_key_hook(data->win_ptr, &handle_input, data);
	mlx_hook(data->win_ptr, 17, 0, &game_destroy, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}

/*
	Ends the game
*/
int	game_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}
