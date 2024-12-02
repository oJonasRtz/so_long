/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:02:05 by jopereir          #+#    #+#             */
/*   Updated: 2024/10/29 10:20:00 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Aply function f at
	the content of lst and creates a new list with that content

	if lstnew fails it delete all the list and returns NULL
	otherwise it return a new list with the new content
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*first;

	if (!lst || !del || !f)
		return (NULL);
	first = NULL;
	while (lst)
	{
		new = ft_lstnew(f(lst -> content));
		if (!new)
		{
			while (first)
			{
				new = first -> next;
				del(first -> content);
				free(first);
				first = new;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&first, new);
		lst = lst -> next;
	}
	return (first);
}
