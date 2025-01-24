/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_operations.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:07:48 by xazuaje-          #+#    #+#             */
/*   Updated: 2025/01/24 14:24:37 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_OPERATIONS_H
# define VEC3_OPERATIONS_H

# include "types.h"
# include <math.h>
# include <libft.h>
# define DEG_TO_RAD 0.017453292519943

t_vec3	add_vec3(t_vec3 v1, t_vec3 v2);
t_vec3	substract_vec3(t_vec3 v1, t_vec3 v2);
t_vec3	normalize_vec3(t_vec3 vec, double module);
double	module_vec3(t_vec3 vec);
t_vec3	cross_product_vec3(t_vec3 v1, t_vec3 v2);
double	dot_product_vec3(t_vec3 v1, t_vec3 v2);
t_vec3	rodrigues_rotation_vec3(t_vec3 v, t_vec3 k, double tetha);
t_vec3	scale_vec3(t_vec3 vec, double scalar);
t_vec3	substract_vec3(t_vec3 v1, t_vec3 v2);
t_vec3	polar_to_n_vec3(double polar, double azimuth);
t_vec3	quaternion_rotation_vec3(t_quat q, t_vec3 v);
int		is_equal_ver3(t_vec3 v1, t_vec3 v2);
#endif //VEC3_OPERATIONS_H
