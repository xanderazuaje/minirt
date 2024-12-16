/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_module.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:36:32 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/12/09 14:39:47 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vec3_operations.h>

double	module_vec3(t_vec3 vec)
{
	return (sqrt(
			pow(vec.x, 2)
			+ pow(vec.y, 2)
			+ pow(vec.z, 2)
		));
}