/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:16:11 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/10 15:39:38 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_lines(int fd)
{
	int		lines;
	char	*temp;

	lines = 0;
	temp = get_next_line(fd);
	while (temp != NULL)
	{
		lines++;
		free(temp);
		temp = get_next_line(fd);
	}
	free(get_next_line(fd));
	return (lines);
}

char	**read_map(char *argv, int *line)
{
	char	**map;
	int		i;
	int		lines;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (NULL);
	lines = get_lines(fd);
	*line = lines;
	ft_printf("Lines counted.\n");
	close (fd);
	fd = open(argv, O_RDONLY);
	map = (char **)ft_calloc(lines + 1, sizeof(char *));
	if (!map)
		return (NULL);
	ft_printf("Map alloc\n");
	i = 0;
	while (i < lines)
		map[i++] = get_next_line(fd);
	free(get_next_line(fd));
	map[i] = NULL;
	ft_printf("Loading map...\n");
	close (fd);
	return (map);
}
