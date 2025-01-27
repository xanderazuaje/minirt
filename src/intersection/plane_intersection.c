/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 21:00:28 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/12/28 23:17:56 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <intersection.h>

short plane_intersection(t_ray ray, t_scene_element *elem, int bounce)
{
	t_plane *p;
    t_vec3 oc; // Vector from ray origin to a point on the plane
    double t;
    double denom;

    p = &elem->plane;
    (void)bounce;

    // Normalize the normal vector (rotate_vec is the normal vector)
    t_vec3 normal = normalize_vec3(p->rotate_vec, p->module); 

    // Calculate the vector from the ray origin to a point on the plane (oc)
    oc = substract_vec3(ray.position, p->coords);

    // Calculate the denominator (dot product of the normal vector and ray's direction)
    denom = dot_product_vec3(normal, ray.normalized);

    // If the denominator is 0, the ray is parallel to the plane
    if (denom == 0)
        return 0;

    // Calculate the intersection parameter t
    t = -dot_product_vec3(normal, oc) / denom;

    // If t is positive, the ray intersects the plane
    if (t > 0.001)  // Some epsilon to avoid intersection with the plane behind the ray
    {
        ray.rgba = p->rgba;  // Assign the plane's color to the ray
        return 1;
    }

    return 0;
	/*t_plane *p;
	p = &elem->plane;
	(void)bounce;
	(void)ray;

	return 0;*/
}
