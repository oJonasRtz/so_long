/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:46:03 by jopereir          #+#    #+#             */
/*   Updated: 2024/10/17 11:53:51 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	delete and free a node and all the sucessors
*/
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*next;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		next = current -> next;
		del(current -> content);
		free(current);
		current = next;
	}
	*lst = NULL;
}
