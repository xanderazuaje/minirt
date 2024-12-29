/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:59:25 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/12/28 19:35:24 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <intersection.h>

short sphere_intersection(t_ray ray, t_scene_element *elem, int bounce)
{
	t_sphere *s;
	t_vec3 moved_sphere;
	double discriminant;

	(void) bounce;
	s = &elem->sphere;
	moved_sphere = substract_vec3(ray.position, s->coords);
	discriminant = pow(dot_product_vec3(ray.direction, moved_sphere), 2)
        - pow(module_vec3(moved_sphere), 2)
        + pow(s->radius, 2);
	if (discriminant < 0)
	{
		return (0);
	}
	ray.rgba = s->rgba;
	return (1);
}
