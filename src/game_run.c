/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:21:39 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/06 11:55:32 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	game_init(t_data *data, char *argv)
{
	int	lines;
	int	fd;

	lines = 0;
	fd = open(argv);
	while (get_next_line(fd) != NULL)
		lines++;
	close(fd);
	fd = open(argv);
	data->map = (char **)ft_calloc(lines + 1, sizeof(char *));
	if (!data->map)
		return (0);
	data->map = get_next_line(fd);
	close(fd);
	return (lines);
}

/*
	starts the game. First events to run
*/
int	game_create(t_data *data, char *argv)
{
	if (!game_init(data, argv))
		return (0);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			data->win_width, data->win_height, "so_long");
	game_step(data);
	return (1);
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
