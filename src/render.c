/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:08:05 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/09 17:11:29 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	Counts how much letters has a string before the charset
*/
static int	ft_strlen_char(char *str, char charset)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != charset)
		i++;
	return (i);
}

void	set_window(t_data *data)
{
	data->win_width = TILE * ft_strlen_char(data->map[0], '\n');
	data->win_height = TILE * data->lines;
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			data->win_width, data->win_height, "so_long");
	ft_printf("height: %d\nwidth: %d\n", data->win_height, data->win_width);
	load_sprites(data);
	render(data);
}

void	load_sprites(t_data *data)
{
	int	height;
	int	width;

	height = 0;
	width = 0;
	data->ground = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/spr_ground.xpm", &width, &height);
	data->wall = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/Wall.xpm", &width, &height);
	data->player = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/spr_player.xpm", &width, &height);
	data->collectables = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/spr_collectable.xpm", &width, &height);
	data->exit = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/spr_exit_closed.xpm", &width, &height);
}

static void	switch_sprite(t_data *data, char c, int x, int y)
{
	if (c == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->ground,
			x, y);
	if (c == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall,
			x, y);
	if (c == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player,
			x, y);
	if (c == 'C')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->collectables, x, y);
			data->collectables_cnt++;
	}
	if (c == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->exit, x, y);
}

void	render(t_data *data)
{
	int	i;
	int	j;

	data->collectables_cnt = 0;
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			switch_sprite(data, data->map[i][j], j * TILE, i * TILE);
			j++;
		}
		i++;
	}
	ft_printf("Collectables: %d\n", data->collectables_cnt);
}
