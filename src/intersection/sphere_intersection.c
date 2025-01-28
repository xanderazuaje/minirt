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

/*||p
w = ray_direction - sphere_center
a = ray_direction * ray_direction
b = 2 * (w * ray_direction)
c = w * w - s_Radius²
discriminant = b² - 4ac
*/
short sphere_intersection(t_ray ray, t_scene_element *elem, int bounce)
{
	t_sphere	*s;
	(void)bounce;
	s = &elem->sphere;

	t_vec3	w = substract_vec3(ray.position, s->coords);
	float	a = dot_product_vec3(ray.direction, ray.direction);
	float	b = 2 * dot_product_vec3(w, ray.direction);
	float	c = (dot_product_vec3(w, w)) - (s->radius * s->radius);
	float	discriminant = (b * b) - (4 * (a * c));

	if (discriminant < 0)
		return (0);

	float	t1 = ((- b) - (sqrt(discriminant))) / (2 * a);
	float	t2 = ((-b) + (sqrt(discriminant))) / (2 * a);

	t_vec3	p1 = add_vec3(ray.position, (t_vec3){t1 * ray.direction.x, t1 * ray.direction.y, t1 * ray.direction.z});
	t_vec3	p2 = add_vec3(ray.position, (t_vec3){t2 * ray.direction.x, t2 * ray.direction.y, t2 * ray.direction.z});

	(void)p1;
	(void)p2;
	return (1);
}
