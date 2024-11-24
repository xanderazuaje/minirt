/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varg_set_null.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 23:47:20 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/07/15 07:11:54 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	varg_set_null(int n, ...)
{
	va_list		ptr;
	void		**ptr2;

	va_start(ptr, n);
	while (n--)
	{
		va_arg(ptr, void **);
		ptr2 = (void **)ptr;
		*ptr2 = NULL;
	}
	va_end(ptr);
}
