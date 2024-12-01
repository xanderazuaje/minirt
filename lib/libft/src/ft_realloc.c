/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 12:22:00 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/12/01 14:49:11 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_realloc(void *ptr, size_t cursize, size_t size)
{
	void	*newptr;

	if (ptr == 0)
		return (safe_malloc(size));
	if (size <= cursize)
		return (ptr);
	newptr = safe_malloc(size);
	ft_memmove(ptr, newptr, cursize);
	free(ptr);
	return (newptr);
}
