/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:30:36 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/09 17:02:32 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define TILE 128

# include "libft.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <mlx.h>

typedef struct s_data
{
	int		fd;
	int		win_height;
	int		win_width;
	int		map_height;
	int		map_width;

	char	**map;
	int		lines;

	void	*mlx_ptr;
	void	*win_ptr;

	void	*player;
	void	*collectables;
	void	*ground;
	void	*wall;
	void	*exit;
	void	*enemy;

	int		collectables_cnt;
}	t_data;

//	Game running
int		game_create(t_data *data, char *argv);
int		game_step(t_data *data);
int		game_destroy(t_data *data);

//	Handle funtions
int		handle_input(int keysym, t_data *data);
int		handle_no_event(void);

//	read_map
char	**read_map(char *argv, int *line);

//	Render
void	set_window(t_data *data);
void	load_sprites(t_data *data);
void	render(t_data *data);

#endif
