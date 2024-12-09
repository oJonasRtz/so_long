/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:48:33 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/09 12:42:31 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <mlx.h>

typedef struct s_data
{
	int		fd;
	int		win_height;
	int		win_width;
	int		map_height;
	int		map_width;

	char	*map;

	void	*mlx_ptr;
	void	*win_ptr;

	void	*player;
	void	*collectables;
	void	*ground;
	void	*wall;
	void	*enemy;
}	t_data;

int	get_key(int keycode, void *param)
{
	(void)param;
	printf("Keycode: %d\n", keycode);
	return (0);
}

int	game_end(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}

/*
	Get_keycodes, do not compile at the final project

		use only for tests
*/
int	main(void)
{
	t_data		data;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 200, 200, "so_long");
	mlx_key_hook(data.win_ptr, &get_key, &data);
	mlx_hook(data.win_ptr, 17, 0, &game_end, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_display(data.mlx_ptr);
	return (0);
}
