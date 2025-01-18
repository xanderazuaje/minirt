/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:59:25 by xazuaje-          #+#    #+#             */
/*   Updated: 2025/01/02 14:08:50 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <intersection.h>

short sphere_intersection(t_ray ray, t_scene_element *elem, int bounce)
{
	t_sphere *s;
	t_vec3 oc;  // Vector from sphere center to ray origin
	double a, b, c;
	double discriminant;
	double t1, t2;

	(void)bounce;
	s = &elem->sphere;
	
	// Calculate vector from sphere center to ray origin
	oc = substract_vec3(ray.position, s->coords);
	
	// Calculate quadratic equation coefficients
	a = dot_product_vec3(ray.normalized, ray.normalized);  // Should be 1.0 if normalized
	b = 2.0 * dot_product_vec3(ray.normalized, oc);
	c = dot_product_vec3(oc, oc) - (s->radius * s->radius);
	
	// Calculate discriminant
	discriminant = b * b - 4 * a * c;
	
	if (discriminant < 0)
		return (0);
		
	// Calculate intersection points
	t1 = (-b - sqrt(discriminant)) / (2.0 * a);
	t2 = (-b + sqrt(discriminant)) / (2.0 * a);
	
	// Check if sphere is in front of the ray
	if (t1 > 0.001 || t2 > 0.001)  // Small epsilon to avoid self-intersection
	{
		ray.rgba = s->rgba;
		return (1);
	}
	
	return (0);
}
