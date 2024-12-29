/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polar_to_n_vec3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 11:51:17 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/12/29 11:53:31 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vec3_operations.h>

t_vec3 polar_to_n_vec3(const double polar, const double azimuth)
{
	return (t_vec3){
		.x = sin(polar) * cos(azimuth),
		.y = sin(polar) * sin(azimuth),
		.z = cos(polar)
	};
}