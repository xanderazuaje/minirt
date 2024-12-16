/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_vec3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:48:23 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/12/15 20:49:46 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vec3_operations.h>

t_vec3	scale_vec3(t_vec3 vec, double scalar)
{
	return (t_vec3{
			vec.x * scalar,
			vec.y * scalar,
			vec.z * scalar
		});
}
