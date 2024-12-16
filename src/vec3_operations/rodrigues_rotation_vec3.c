/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rodrigues_rotation_vec3.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:42:38 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/12/15 21:12:44 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vec3_operations.h>

t_vec3 rodrigues_rotation_vec3(t_vec3 v, t_vec3 k, double tetha)
{
	return (add_vec3(
		add_vec3(
			scale_vec3(
				v,
				cos(tetha)
				),
			scale_vec3(
				cross_product_vec3(
					k,
					v
				),
				sin(tetha)
				)
		),
		scale_vec3(
			k,
			dot_product_vec3(k, v) * (1-cos(tetha))
				)
		));
}
