/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:30:36 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/10 14:15:50 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define TILE 64

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

	int		x;
	int		y;
	int		collectables_cnt;
}	t_data;

//	Game running
void	init_values(t_data *data);
int		game_create(t_data *data, char *argv);
int		game_step(t_data *data);
int		game_destroy(t_data *data);

//	Handle funtions
int		handle_input(int keysym, t_data *data);
int		handle_no_event(void);

//	Draw_text
void	*draw_text_void(char *s);
int		draw_text_int(char *s);

//	read_map
char	**read_map(char *argv, int *line);
int		map_is_valid(char **map);

//	Render
int		set_window(t_data *data);
void	load_sprites(t_data *data);
void	render(t_data *data);
int		ft_strlen_char(char *str, char charset);

//	Movement
void	move_player(t_data *data, int x_direction, int y_direction);
int		key_pressed(int key);

#endif
