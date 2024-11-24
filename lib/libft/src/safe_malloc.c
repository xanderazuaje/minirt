/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_malloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xander <xander@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:13:33 by xander            #+#    #+#             */
/*   Updated: 2024/06/12 01:12:54 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*safe_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		perror("malloc:");
		exit(1);
	}
	return (ptr);
}
