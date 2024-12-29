/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 09:04:35 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/12/29 11:58:31 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <types.h>
#include <parser.h>

void free_scene(t_scene *scene)
{
	free(scene->cameras);
	free(scene->lights);
	free(scene->element_list.elements);
	free(scene->element_list.types);
}

void init_scene(t_scene *scene)
{
	scene->element_list.elements = NULL;
	scene->cameras = NULL;
	scene->element_count = 0;
	scene->camera_count = 0;
	scene->lights_count = 0;
}

int get_rgba(t_rgba a)
{
	return (a.r << 24 | a.g << 16 | a.b << 8 | a.a);
}

mlx_image_t *show_angles(t_camera camera, mlx_t *mlx)
{
	int coords[2];
	mlx_image_t *img;
	t_ray *rays;

	img = mlx_new_image(mlx, mlx->width, mlx->height);
	if (!img)
		return NULL;
	rays = (t_ray *)malloc(sizeof(t_ray) * mlx->width * mlx->height);
	coords[0] = 0;
	coords[1] = 1;
	while (coords[0] < mlx->width)
	{
		while (coords[1] < mlx->height)
		{
			double nx;
			double ny;
			double polar;
			double azimuth;
			t_ray ray;
			ny = (coords[1] - WIN_HEIGHT / 2.0)/(WIN_HEIGHT/2.0);
			nx = (coords[0] - WIN_WIDTH / 2.0)/(WIN_WIDTH/2.0);
			polar = ny * (21);
			azimuth = nx * (camera.fov / 2.0);
			ray.position = camera.coords;
			ray.direction = polar_to_n_vec3(polar, azimuth);
			ray.normalized = normalize_vec3(
				ray.position,
				module_vec3(ray.position)
			);
			printf("x: %f | y: %f | z %f\n", ray.direction.x, ray.direction.y, ray.direction.z);
			coords[1]++;
		}
		coords[1] = 0;
		coords[0]++;
	}
	free(rays);
	return (img);
}

int	main(int argc, char **argv)
{
	t_scene scene;
	mlx_t	*mlx;
	mlx_image_t *img;

	init_scene(&scene);
	initial_check(argc, argv);
	parse_rt_file(argv[1], &scene);
	mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "minirt", false);
	img = show_angles(scene.cameras[0], mlx);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	free_scene(&scene);
	return (0);
}
