/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:30:36 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/03 13:45:27 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include <X11/keysym.h>

typedef struct s_data
{
	int		fd;
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

#endif
