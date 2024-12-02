/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:55:44 by jopereir          #+#    #+#             */
/*   Updated: 2024/10/17 12:00:19 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Aplly function f at each node os the list
*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;
	t_list	*next;

	if (!lst || !f)
		return ;
	current = lst;
	while (current)
	{
		next = current -> next;
		f(current -> content);
		current = next;
	}
}
