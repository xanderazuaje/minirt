/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_quaternion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 02:58:16 by xazuaje-          #+#    #+#             */
/*   Updated: 2025/01/04 03:01:20 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <quaternion_operations.h>

t_quat multiply_quaternion(t_quat q1, t_quat q2)
{
	return (t_quat){
		.w = q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z,
		.x = q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y,
		.y = q1.w * q2.y - q1.x * q2.z + q1.y * q2.w + q1.z * q2.x,
		.z = q1.w * q2.z + q1.x * q2.y - q1.y * q2.x + q1.z * q2.w
	};
}
