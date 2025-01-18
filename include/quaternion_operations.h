/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion_operations.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 02:21:29 by xazuaje-          #+#    #+#             */
/*   Updated: 2025/01/04 18:26:05 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef QUATERNION_OPERATIONS_H
#define QUATERNION_OPERATIONS_H

# include "types.h"
# include <math.h>
#include <vec3_operations.h>

t_quat	conj_quaternion(t_quat q);
t_quat	multiply_quaternion(t_quat q1, t_quat q2);
t_quat	normalize_quaternion(t_quat q);
t_vec3	rotate_vec3_quaternion(t_quat q, t_vec3 v);
t_quat	vec3_to_quaternion(t_vec3 direction);

#endif
