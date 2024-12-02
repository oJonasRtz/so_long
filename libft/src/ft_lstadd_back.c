/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:19:55 by jopereir          #+#    #+#             */
/*   Updated: 2024/10/17 12:47:04 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	add a note in the last position of a list

	if node is empty add new as the first node
*/
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_pos;

	if (!lst || !new)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		last_pos = ft_lstlast(*lst);
		last_pos -> next = new;
	}
}
