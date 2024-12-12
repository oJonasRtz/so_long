/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:08:05 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/12 15:56:03 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	Counts how much letters has a string before the charset
*/
int	ft_strlen_char(char *str, char charset)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != charset)
		i++;
	return (i);
}

int	set_window(t_data *data)
{
	data->win_width = TILE * ft_strlen_char(data->map[0], '\n');
	data->win_height = TILE * data->lines;
	if (data->win_height > 1080 || data->win_width > 1920)
		game_destroy(data, "Error: Map is too large.");
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			data->win_width, data->win_height, "so_long");
	if (!data->win_ptr)
		game_destroy(data, "Error: Couldn't open the window.");
	load_sprites(data);
	render(data);
	return (1);
}

void	load_sprites(t_data *data)
{
	int	height;
	int	width;

	height = 0;
	width = 0;
	data->ground = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/xpm/spr_ground_64.xpm", &width, &height);
	data->wall = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/xpm/spr_wall.xpm", &width, &height);
	data->player = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/xpm/spr_fat_cat.xpm", &width, &height);
	data->collectables = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/xpm/spr_food.xpm", &width, &height);
	data->exit = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/xpm/spr_exit_closed.xpm", &width, &height);
}

static void	switch_sprite(t_data *data, char c, int x, int y)
{
	void	*temp;

	temp = NULL;
	if (c == '0')
		temp = data->ground;
	if (c == '1')
		temp = data->wall;
	if (c == 'P')
	{
		temp = data->player;
		data->x = x;
		data->y = y;
	}
	if (c == 'C')
		temp = data->collectables;
	if (c == 'E')
		temp = data->exit;
	if (temp)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, temp, x, y);
}

void	render(t_data *data)
{
	int	i;
	int	j;

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
}
