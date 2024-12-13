/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:30:36 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/13 11:37:31 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define TILE 64

# include "libft.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <mlx.h>

typedef struct s_keys
{
	int	right;
	int	left;
	int	up;
	int	down;
}	t_keys;

typedef struct s_data
{
	int		fd;
	int		win_height;
	int		win_width;
	int		screen_height;
	int		screen_width;
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

	int		icnt;
	int		update;
	char	*message;

	int		x;
	int		y;
	int		moves;
	int		collectables_cnt;
}	t_data;

//	Game running
void	init_values(t_data *data);
int		game_create(t_data *data, char *argv);
int		game_step(t_data *data);
int		game_destroy(t_data *data, char *message);

//	Handle funtions
int		handle_input(int keysym, t_data *data);
int		handle_no_event(t_data *data);

//	read_map
char	**read_map(char *argv, int *line);
int		map_is_valid(t_data *data);
int		is_all_one(char *line);
int		first_and_last_is_one(char *line);

//	Render
int		set_window(t_data *data);
void	load_sprites(t_data *data);
void	render(t_data *data);
int		ft_strlen_char(char *str, char charset);

//	Movement
void	move_player(t_data *data, int x_direction, int y_direction);
int		key_pressed(int key);
t_keys	get_keys(int key);

#endif
