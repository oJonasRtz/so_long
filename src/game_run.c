/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:21:39 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/10 13:46:18 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

/*
	starts the game. First events to run
*/
int	game_create(t_data *data, char *argv)
{
	char	**temp;

	temp = read_map(argv, &data->lines);
	data->map = temp;
	if (!data->map)
		return (draw_text_int("Couldn't read the map.\n"));
	if (!map_is_valid(data->map))
	{
		free_map(temp);
		return (draw_text_int("Invalid map.\n"));
	}
	ft_printf("Map successfully loaded.\n");
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		free_map(temp);
		return (draw_text_int("Error initializing MLX.\n"));
	}
	ft_printf("MLX initialized\n");
	set_window(data);
	game_step(data);
	free_map(temp);
	return (1);
}

/*
	runs the game. Frame per frame

	mlx_hook - calls game_destroy when click on window's 'x'
*/
int	game_step(t_data *data)
{
	ft_printf("Looping(step)...\n");
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
	init_values(data);
}

/*
	Ends the game
*/
int	game_destroy(t_data *data)
{
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free_images(data);
	if (data->map)
		free_map(data->map);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	ft_printf("game destroy.\n");
	return (0);
}
