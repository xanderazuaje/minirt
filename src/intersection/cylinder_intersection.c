/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 21:00:41 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/12/17 21:57:02 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <intersection.h>
/*
w = ray_origin - cylinder_center
d_perpendicular = ray_direction - (ray_direction · c_axis) * c_axis
w_perpendicular = w - (w · w) * c_axis
discriminant = b² - 4ac
*/

/*int cylinder_intersection(t_ray ray, t_scene_element *elem, int bounce)
{
	t_cylinder	*cy;
	(void)bounce;
	cy = &elem->cylinder;

	t_vec3 ctop = add_vec3(cy->coords, (t_vec3){(cy->height / 2) * cy->rotate_vec.x, (cy->height / 2) * cy->rotate_vec.y, (cy->height / 2) * cy->rotate_vec.z});
	t_vec3 ctop = substract_vec3(cy->coords, (t_vec3){(cy->height / 2) * cy->rotate_vec.x, (cy->height / 2) * cy->rotate_vec.y, (cy->height / 2) * cy->rotate_vec.z});

}*/

int cylinder_intersection(t_ray ray, t_scene_element *elem, int bounce)
{
	t_cylinder *cy;
	(void)bounce;
	cy = &elem->cylinder;

	t_vec3	w = substract_vec3(ray.position, cy->coords);
	float	d_o_a = dot_product_vec3(ray.normalized, cy->rotate_vec);
	t_vec3	d_perpendicular = substract_vec3(ray.normalized, (t_vec3){cy->rotate_vec.x * d_o_a, cy->rotate_vec.y * d_o_a, cy->rotate_vec.z * d_o_a});
	float	w_o_a = dot_product_vec3(w, cy->rotate_vec);
	t_vec3	w_perpendicular = substract_vec3(w, (t_vec3){cy->rotate_vec.x * w_o_a, cy->rotate_vec.y * w_o_a, cy->rotate_vec.z * w_o_a});

	float	a = dot_product_vec3(d_perpendicular, d_perpendicular);
	float	b = 2 * dot_product_vec3(w_perpendicular, d_perpendicular);
	float	c = dot_product_vec3(w_perpendicular, w_perpendicular) - ((cy->diameter / 2) * (cy->diameter / 2));

	float	discriminant = (b * b) - (4.0 * (a * c));

	if (discriminant < 0 || a == 0)
		return (0);
	
	float	t1 = ((-b) - (sqrt(discriminant))) / (2.0 * a);
	float	t2 = ((-b) + (sqrt(discriminant))) / (2.0 * a);

	//if (t1 < 0 && t2 < 0)
	//	return (0);

	t_vec3	p1 = add_vec3(ray.position, (t_vec3){t1 * ray.normalized.x, t1 * ray.normalized.y, t1 * ray.normalized.z});
	t_vec3	p2 = add_vec3(ray.position, (t_vec3){t2 * ray.normalized.x, t2 * ray.normalized.y, t2 * ray.normalized.z});

	(void)p1;
	(void)p2;

	//float	h1 = dot_product_vec3(substract_vec3(p1, cy->coords), cy->rotate_vec);
	//float	h2 = dot_product_vec3(substract_vec3(p2, cy->coords), cy->rotate_vec);
	float	o_less_c_o_a = dot_product_vec3(substract_vec3(ray.position, cy->coords), cy->rotate_vec);
	float	h1 = o_less_c_o_a + t1 * dot_product_vec3(ray.normalized, cy->rotate_vec);
	float	h2 = o_less_c_o_a + t2 * dot_product_vec3(ray.normalized, cy->rotate_vec);
	if ((h1 > (-(cy->height / 2)) && h1 < (cy->height / 2)) || (h2 > (-(cy->height / 2)) && h2 < (cy->height / 2)))
		return (1);
	return (0);
}
