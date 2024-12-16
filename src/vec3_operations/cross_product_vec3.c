/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_product_vec3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 20:23:30 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/12/15 20:39:34 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vec3_operations.h>

t_vec3 cross_product_vec3(t_vec3 v1, t_vec3 v2)
{
	return (t_vec3){
		v1.y * v2.z - v1.z * v2.y,
		-(v1.x * v2.z - v1.z * v2.x),
		v1.x * v2.y - v1.y * v2.x
	};
}
