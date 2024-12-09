/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:48:32 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/09 15:17:04 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_no_event(void)
{
	return (0);
}

int	handle_input(int keysym, t_data *data)
{
	if (keysym == 65307)
		game_destroy(data);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		return (ft_printf("Too few argumments.\n"));
	ft_printf("\nExcluir comentarios de Debug futuramente\n\n");
	game_create(&data, argv[1]);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	ft_printf("Jogo encerrado com sucesso!\n\n");
	return (0);
}
