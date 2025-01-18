/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polar_to_n_vec3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 11:51:17 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/12/29 13:02:26 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vec3_operations.h>

t_vec3	polar_to_n_vec3(double polar, double azimuth)
{
	polar = polar * (M_PI / 180.0);
    azimuth = azimuth * (M_PI / 180.0);
	return ((t_vec3){
		.x = sin(polar) * cos(azimuth),
		.y = sin(polar) * sin(azimuth),
		.z = cos(polar)
	});
}
