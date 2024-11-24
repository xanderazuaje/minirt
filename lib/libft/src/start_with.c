/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_with.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:46:04 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/10/31 14:15:17 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	start_with(const char *str, const char *find)
{
	while (*str && *find)
	{
		if (*str != *find)
			return (0);
		str++;
		find++;
	}
	if (!*find && (*str == '=' || *str == '\0'))
		return (1);
	return (0);
}
