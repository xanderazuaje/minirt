/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_splitted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 02:34:51 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/07/15 07:14:45 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_splitted(t_splitted **s)
{
	if (!*s)
	{
		return ;
	}
	while ((*s)->len)
	{
		free((*s)->string[(*s)->len - 1]);
		(*s)->len--;
	}
	free((*s)->string);
	free(*s);
}
