/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 09:04:35 by xazuaje-          #+#    #+#             */
/*   Updated: 2025/01/24 14:32:20 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <types.h>
#include <parser.h>
#include <quaternion_operations.h>
#include <camera_controls.h>
#include <rays.h>

void free_scene(t_scene *scene)
{
	free(scene->cameras);
	free(scene->lights);
	free(scene->element_list.elements);
	free(scene->element_list.types);
	free(scene->element_list.func);
}

void init_scene(t_scene *scene)
{
	scene->element_list.elements = NULL;
	scene->element_list.types = NULL;
	scene->element_list.func = NULL;
	scene->lights = NULL;
	scene->cameras = NULL;
	scene->element_count = 0;
	scene->camera_count = 0;
	scene->lights_count = 0;
}

int get_rgba(t_rgba a)
{
	return (a.r << 24 | a.g << 16 | a.b << 8 | a.a);
}
 /*good one*/
/*t_ray init_ray(t_camera camera, const int coords[2])
{
	double nx;
	double ny;
	double aspect_ratio;
	t_ray ray;

	aspect_ratio = WIN_WIDTH / WIN_HEIGHT;

	ny = (coords[1] - WIN_HEIGHT / 2.0) / (WIN_HEIGHT / 2.0);
	nx = ((coords[0] - WIN_WIDTH / 2.0) / (WIN_WIDTH / 2.0)) * aspect_ratio;
	ray.position = camera.coords;

	ray.direction = polar_to_n_vec3(ny * (camera.fov) + 90, nx * (camera.fov));
	ray.normalized = normalize_vec3(ray.direction, module_vec3(ray.direction));
	ray.rgba = (t_rgba){0, 0, 0, 0};//colores

	return (ray);
}*/

#include <math.h>

/*t_ray init_ray(t_camera camera, const int coords[2])
{
	t_vec3 forward = rotate_vector(camera.rotation, (t_vec3){0.0f, 0.0f, -1.0f});
	t_vec3 up = rotate_vector(camera.rotation, (t_vec3){0.0f, 1.0f, 0.0f});
	t_vec3 right = rotate_vector(camera.rotation, (t_vec3){1.0f, 0.0f, 0.0f});

	forward = normalize_vec3(forward, sqrt(forward.x * forward.x + forward.y * forward.y + forward.z * forward.z));
	up = normalize_vec3(up, sqrt(up.x * up.x + up.y * up.y + up.z * up.z));
	right = normalize_vec3(right, sqrt(right.x * right.x + right.y * right.y + right.z * right.z));

	float	aspect_ratio = WIN_WIDTH / WIN_HEIGHT;
	float	screen_half_height = tanf((camera.fov * 0.5f) * (3.14159265358979323846 / 180.0f)); /// 2.0f or *0.5f
	float	screen_half_width = screen_half_height * aspect_ratio;

	//t_vec3 screen_center = {
	//	camera.coords.x + forward.x,
	//	camera.coords.y + forward.y,
	//	camera.coords.z + forward.z};

	//LOOP
	float u = (coords[1] / (WIN_WIDTH - 1)) * 2.0f - 1.0f; //(2 * ((coords[1] + 0.5f) / WIN_WIDTH) - 1) * screen_half_width;
	float v = (coords[0] / (WIN_HEIGHT - 1)) * 2.0f - 1.0f; //(1 - 2 *((coords[0] + 0.5f) / WIN_HEIGHT)) * screen_half_height;

	t_vec3 screen_point = {
		u * screen_half_width,
		v * screen_half_height,
		0.0f};

	t_ray ray;

	ray.direction = (t_vec3){
		screen_point.x * right.x + screen_point.y * up.x + forward.x,
		screen_point.x * right.y + screen_point.y * up.y + forward.y,
		screen_point.x * right.z + screen_point.y * up.z + forward.z};
	ray.normalized = normalize_vec3(ray.direction, sqrt(ray.direction.x * ray.direction.x + ray.direction.y * ray.direction.y + ray.direction.z * ray.direction.z));
	ray.position = camera.coords;

	//t_vec3 pixel_pos = {
	//	screen_center.x + u * right.x + v * up.x,
	//	screen_center.y + u * right.y + v * up.y,
	//	screen_center.z + u * right.z + v * up.z,
	//};

	//t_ray ray;
	//t_vec3 substract = substract_vec3(pixel_pos, camera.coords);
	//ray.direction = normalize_vec3(substract, sqrt(substract.x * substract.x + substract.y * substract.y + substract.z * substract.z));
	//ray.position = camera.coords;
	ray.rgba = (t_rgba){0, 0, 0, 0};
	return (ray);
}*/

int	main(int argc, char **argv)
{
	t_scene scene;
	mlx_t	*mlx;
	t_ray *rays;

	init_scene(&scene);
	initial_check(argc, argv);
	parse_rt_file(argv[1], &scene);
	mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "minirt", false);
	rays = set_rays(scene.cameras[0], mlx);
	scene.img = mlx_new_image(mlx, mlx->width, mlx->height);
	int xy[2];
	xy[0] = 0;
	xy[1] = 0;
	scene.mlx = mlx;
	mlx_loop_hook(mlx, camera_controls, &scene);/*esto no va a hacer q todo vaya muy lento si tiene q retrazar los rayos todo el tiempo?*/
	mlx_image_to_window(mlx, scene.img, 0, 0);
	mlx_loop(mlx);
	mlx_delete_image(mlx, scene.img);
	mlx_terminate(mlx);
	free_scene(&scene);
	free(rays);
	
	return (0);
}
