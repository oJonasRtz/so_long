/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:26:27 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/10 10:28:38 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	Functions of errors

	draw the text and return error results
*/
int	draw_text_int(char *s)
{
	ft_putstr_fd(s, 1);
	return (0);
}

void	*draw_text_void(char *s)
{
	ft_putstr_fd(s, 1);
	return (NULL);
}
