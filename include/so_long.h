/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:30:36 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/06 11:33:42 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define TILE 128

# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include <X11/keysym.h>

typedef struct s_data
{
	int		fd;
	int		win_height;
	int		win_width;
	int		map_height;
	int		map_width;

	char	**map;

	void	*mlx_ptr;
	void	*win_ptr;

	void	*player;
	void	*collectables;
	void	*ground;
	void	*wall;
	void	*enemy;
}	t_data;

//	Game running
int	game_create(t_data *data, char *argv);
int	game_step(t_data *data);
int	game_destroy(t_data *data);

//	Handle funtions
int	handle_input(int keysym, t_data *data);
int	handle_no_event(void);

#endif
