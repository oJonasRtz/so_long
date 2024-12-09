/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:21:39 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/09 13:57:27 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	starts the game. First events to run
*/
int	game_create(t_data *data, char *argv)
{
	data->map = read_map(argv);
	if (!data->map)
		return (0);
	ft_printf("Mapa lido com sucesso.\n");
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (0);
	ft_printf("MLX iniciado\n");
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			data->win_width, data->win_height, "so_long");
	ft_printf("Janela aberta com sucesso.\n");
	if (!data->mlx_ptr)
		return (0);
	game_step(data);
	return (1);
}

/*
	runs the game. Frame per frame

	mlx_hook - calls game_destroy when click on window's 'x'
*/
int	game_step(t_data *data)
{
	ft_printf("Rodando loop(step)...\n");
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
	int	i;

	i = 0;
	while (data->map[i])
		free(data->map[i++]);
	free(data->map);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	ft_printf("game destroy.\n");
	return (0);
}
