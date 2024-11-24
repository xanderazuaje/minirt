/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 09:48:48 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/11/24 10:37:32 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	ft_error(void)
{
	ft_putendl_fd(mlx_strerror(mlx_errno), 2);
	exit(EXIT_FAILURE);
}
