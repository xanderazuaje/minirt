/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion_rotation_vec3.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:21:04 by xazuaje-          #+#    #+#             */
/*   Updated: 2025/01/24 14:26:26 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <quaternion_operations.h>
#include <types.h>

t_vec3	quaternion_rotation_vec3(t_quat q, t_vec3 v)
{
	t_quat p, qp, q_conj, result;

	p = (t_quat){0, v.x, v.y, v.z};
	qp = (t_quat){
		q.w * p.w - q.x * p.x - q.y * p.y - q.z * p.z,
        q.w * p.x + q.x * p.w + q.y * p.z - q.z * p.y,
        q.w * p.y - q.x * p.z + q.y * p.w + q.z * p.x,
        q.w * p.z + q.x * p.y - q.y * p.x + q.z * p.w
	};
	q_conj = conj_quaternion(q);
	result = (t_quat){
		qp.w * q_conj.w - qp.x * q_conj.x - qp.y * q_conj.y - qp.z * q_conj.z,
        qp.w * q_conj.x + qp.x * q_conj.w + qp.y * q_conj.z - qp.z * q_conj.y,
        qp.w * q_conj.y - qp.x * q_conj.z + qp.y * q_conj.w + qp.z * q_conj.x,
        qp.w * q_conj.z + qp.x * q_conj.y - qp.y * q_conj.x + qp.z * q_conj.w
	};
	return ((t_vec3){result.x, result.y, result.z});
}
