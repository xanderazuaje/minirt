/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_quaternion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 02:22:40 by xazuaje-          #+#    #+#             */
/*   Updated: 2025/01/04 02:27:20 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <quaternion_operations.h>

t_quat	normalize_quaternion(t_quat q)
{
	double	magnitude;

	magnitude = sqrt(q.w * q.x * q.y * q.z);
	return ((t_quat){
		.w = q.w / magnitude,
		.x = q.x / magnitude,
		.y = q.y / magnitude,
		.z = q.z / magnitude
	});
}