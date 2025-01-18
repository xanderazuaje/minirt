/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_to_quaternion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 03:09:46 by xazuaje-          #+#    #+#             */
/*   Updated: 2025/01/04 03:10:06 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <quaternion_operations.h>

t_quat vec3_to_quaternion(t_vec3 direction)
{
	t_vec3 base = {0.0, 0.0, -1.0};

	// Eje de rotación entre la dirección base y la nueva dirección
	t_vec3 axis = cross_product_vec3(base, direction);
	double axis_length = module_vec3(axis);

	// Asegurarse de que el eje es válido
	if (axis_length == 0.0)
		axis = (t_vec3){1.0, 0.0, 0.0}; // Rotación nula (apunta en Z)

	axis = normalize_vec3(axis, axis_length);

	// Ángulo entre la dirección base y la nueva dirección
	double angle = acos(dot_product_vec3(base, direction) / module_vec3(direction));

	// Convertir a cuaternión
	double half_angle = angle / 2.0;
	double sin_half = sin(half_angle);

	return (t_quat){
		.w = cos(half_angle),
		.x = axis.x * sin_half,
		.y = axis.y * sin_half,
		.z = axis.z * sin_half
	};
}
