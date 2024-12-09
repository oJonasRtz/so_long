/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:33:20 by jopereir          #+#    #+#             */
/*   Updated: 2024/10/28 14:54:17 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free(char *str, char *str2)
{
	free(str);
	free(str2);
	return (NULL);
}

/*
	takes a buffer and copy it to a temp string until \n
*/
static char	*get_line(char *buffer)
{
	char	*temp;
	int		i;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	temp = ft_calloc(i + 2, sizeof(char));
	if (!temp)
		return (ft_free(buffer, NULL));
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
	{
		temp[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		temp[i] = '\n';
	return (temp);
}

/*
	Takes a buffer and a file descriptor and concatenate it until \n
*/
static char	*get_endl(int fd, char *buffer)
{
	int		rd;
	char	*temp;
	char	*new_buffer;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, temp, BUFFER_SIZE);
		if (rd == (-1))
			return (ft_free(buffer, temp));
		temp[rd] = 0;
		new_buffer = ft_strjoin(buffer, temp);
		free(buffer);
		buffer = new_buffer;
		if (ft_strchr(temp, '\n'))
			break ;
	}
	free(temp);
	if (rd == 0 && (!buffer || buffer[0] == '\0'))
		return (ft_free(buffer, NULL));
	return (buffer);
}

/*
	Erases the last readed line of the buffer
*/
static char	*get_buffer_update(char *buffer)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (ft_free(buffer, NULL));
	temp = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (!temp)
		return (ft_free(buffer, NULL));
	i++;
	j = 0;
	while (buffer[i])
		temp[j++] = buffer[i++];
	free(buffer);
	return (temp);
}

/*
	shows the content of a file line by line

	if its called one shows the first line
	if it twice shows the second line
*/
char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd == (-1) || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = get_endl(fd, buffer);
	if (!buffer || buffer[0] == '\0')
		return (NULL);
	line = get_line(buffer);
	if (!line || line[0] == '\0')
		return (ft_free(buffer, line));
	buffer = get_buffer_update(buffer);
	return (line);
}
