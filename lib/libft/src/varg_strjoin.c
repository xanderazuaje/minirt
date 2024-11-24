/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varg_strjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 04:28:50 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/06/12 04:29:22 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*varg_strjoin(int n, ...)
{
	char	*final;
	char	*temp;
	va_list	str;

	final = NULL;
	va_start(str, n);
	while (n--)
	{
		temp = final;
		final = ft_strjoin(final, va_arg(str, char *));
		free(temp);
	}
	va_end(str);
	return (final);
}
