/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:21:39 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/13 10:34:14 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
		free(data->map[i++]);
	free(data->map);
}

/*
	starts the game. First events to run
*/
int	game_create(t_data *data, char *argv)
{
	data->map = read_map(argv, &data->lines);
	if (!data->map)
		game_destroy(data, "Error: Couldn't read the map.");
	if (!map_is_valid(data))
		game_destroy(data, "Error: Invalid map.");
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		game_destroy(data, "Error: Couldn't initializing MLX.");
	set_window(data);
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

static void	free_images(t_data *data)
{
	if (data->collectables)
		mlx_destroy_image(data->mlx_ptr, data->collectables);
	if (data->wall)
		mlx_destroy_image(data->mlx_ptr, data->wall);
	if (data->player)
		mlx_destroy_image(data->mlx_ptr, data->player);
	if (data->ground)
		mlx_destroy_image(data->mlx_ptr, data->ground);
	if (data->exit)
		mlx_destroy_image(data->mlx_ptr, data->exit);
	if (data->enemy)
		mlx_destroy_image(data->mlx_ptr, data->enemy);
}

/*
	Ends the game
*/
int	game_destroy(t_data *data, char *message)
{
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free_images(data);
	if (data->map)
		free_map(data);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	init_values(data);
	if (!message)
		exit (0);
	if (ft_strncmp(message, "!", 2) == 0)
		ft_printf("Game closed by the player.\n");
	else
		ft_printf("%s\n", message);
	exit (0);
}
