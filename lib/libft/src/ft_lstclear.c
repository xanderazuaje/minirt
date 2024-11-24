/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:03:18 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/09/21 22:58:07 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*prev;

	prev = lst[0];
	current = lst[0];
	if (!prev)
		return ;
	if (prev->next)
	{
		while (prev->next)
		{
			current = prev->next;
			del(prev->content);
			free(prev);
			prev = current;
		}
		del(current->content);
		free(current);
	}
	else
	{
		del(prev->content);
		free(prev);
	}
	*lst = 0;
}
