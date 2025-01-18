/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_vec3_quaternion.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 02:58:50 by xazuaje-          #+#    #+#             */
/*   Updated: 2025/01/04 03:06:40 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <quaternion_operations.h>

t_vec3	rotate_vec3_quaternion(t_quat q, t_vec3 v)
{
	t_quat	q_v;
	t_quat	q_conj;
	t_quat	q_rotated;

	q_v = (t_quat){.w = 0, .x = v.x, .y = v.y, .z = v.z};
	q_conj = conj_quaternion(q);
	q_rotated = multiply_quaternion(multiply_quaternion(q, q_v), q_conj);

	return ((t_vec3){.x = q_rotated.x, .y = q_rotated.y, .z = q_rotated.z});
}
