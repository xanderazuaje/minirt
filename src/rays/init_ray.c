/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:29:34 by xazuaje-          #+#    #+#             */
/*   Updated: 2025/01/24 14:30:24 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rays.h>
#define M_PI 3.14159265358979323846

t_ray init_ray(t_camera camera, const int coords[2])
{
	t_vec3 w = quaternion_rotation_vec3(camera.rotation, (t_vec3){0, 0, -1});
	t_vec3 upxw = cross_product_vec3((t_vec3){0, 1, 0}, w);
	t_vec3 u = normalize_vec3(upxw, sqrt(upxw.x * upxw.x + upxw.y * upxw.y + upxw.z * upxw.z));
	t_vec3 v = cross_product_vec3(w, u);

	w = normalize_vec3(w, sqrt(w.x * w.x + w.y * w.y + w.z * w.z));
	u = normalize_vec3(u, sqrt(u.x * u.x + u.y * u.y + u.z * u.z));
	v = normalize_vec3(v, sqrt(v.x * v.x + v.y * v.y + v.z * v.z));

	camera.fov = camera.fov * (M_PI / 180);
	float aspect_ratio = WIN_WIDTH / WIN_HEIGHT;
	float f_len = tanf(camera.fov / 2);
	//float width = aspect_ratio * height;

	float nx = ((2 * (coords[0] + 0.5) / WIN_WIDTH) - 1) * aspect_ratio * f_len;
	float ny = (1 - 2 * ((coords[1] + 0.5) / WIN_HEIGHT)) * f_len;
	t_vec3 mid1_pixel_pos = {((nx) * u.x), ((nx) * u.y), ((nx) * u.z)};
	t_vec3 mid2_pixel_pos = {((ny ) * v.x), ((ny ) * v.y), ((ny ) * v.z)};
	t_vec3 pixel_pos = {mid1_pixel_pos.x + mid2_pixel_pos.x - w.x,
						mid1_pixel_pos.y + mid2_pixel_pos.y - w.y,
						mid1_pixel_pos.z + mid2_pixel_pos.z - w.z};

	t_ray ray;
	ray.direction = normalize_vec3(pixel_pos, sqrt(pixel_pos.x * pixel_pos.x + pixel_pos.y * pixel_pos.y + pixel_pos.z * pixel_pos.z));
	ray.normalized = normalize_vec3(ray.direction, sqrt(ray.direction.x * ray.direction.x + ray.direction.y * ray.direction.y + ray.direction.z * ray.direction.z));
	ray.position = camera.coords;
	ray.rgba = (t_rgba){0, 0, 0, 0};
	return (ray);
}
