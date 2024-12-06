/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:48:32 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/06 11:29:30 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_no_event(void)
{
	return (0);
}

int	handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		game_destroy(data);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		return (ft_printf("Too few argumments."));
	data.win_height = 1080;
	data.win_width = 1920;
	game_create(&data, argv[1]);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}
