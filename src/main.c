/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 09:04:35 by xazuaje-          #+#    #+#             */
/*   Updated: 2025/01/18 16:43:30 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <types.h>
#include <parser.h>
#include <quaternion_operations.h>

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
	scene->element_count = 0;
	scene->camera_count = 0;
	scene->lights_count = 0;
}

int get_rgba(t_rgba a)
{
	return (a.r << 24 | a.g << 16 | a.b << 8 | a.a);
}

t_ray init_ray(t_camera camera, const int coords[2])
{
	double nx;
	double ny;
	double aspect_ratio;
	t_ray ray;

	aspect_ratio = WIN_WIDTH / WIN_HEIGHT;

	ny = (coords[1] - WIN_HEIGHT / 2.0) / (WIN_HEIGHT / 2.0);
	nx = ((coords[0] - WIN_WIDTH / 2.0) / (WIN_WIDTH / 2.0)) * aspect_ratio;
	ray.position = camera.coords;

	ray.direction = polar_to_n_vec3(
		ny * (camera.fov) + 90,
		nx * (camera.fov)
	);
	ray.normalized = normalize_vec3(ray.direction, module_vec3(ray.direction));
	ray.rgba = (t_rgba){0, 0, 0, 0};

	return (ray);
}

t_ray	*set_rays(t_camera camera, mlx_t *mlx)
{
	int		xy[2];
	t_ray	*rays;

	rays = (t_ray *)safe_malloc(sizeof(t_ray) * mlx->width * mlx->height);
	xy[0] = 0;
	while (xy[0] < mlx->width)
	{
		xy[1] = 0;
		while (xy[1] < mlx->height)
		{
			rays[xy[0] * mlx->height + xy[1]] = init_ray(camera, xy);
			xy[1]++;
		}
		xy[0]++;
	}
	return (rays);
}

//TODO: Hacer que muva la cámara
void key_hook(void *param)
{
    t_scene *scene;
    mlx_t *mlx;
    float move_speed;

    scene = ((t_scene *)param);
    mlx = scene->mlx;
    move_speed = 0.5f;

    if (mlx_is_key_down(mlx, MLX_KEY_UP))
        scene->cameras[0].coords.x += move_speed;
    if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
        scene->cameras[0].coords.x -= move_speed;
    if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
        scene->cameras[0].coords.y += move_speed;
    if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
        scene->cameras[0].coords.y -= move_speed;
    if (mlx_is_key_down(mlx, MLX_KEY_J))
        scene->cameras[0].coords.z += move_speed;
    if (mlx_is_key_down(mlx, MLX_KEY_K))
        scene->cameras[0].coords.z -= move_speed;
    if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
        mlx_close_window(mlx);

    // Recalculate rays and redraw image
    t_ray *rays = set_rays(scene->cameras[0], mlx);
    int xy[2] = {0, 0};

    while (xy[0] < mlx->width)
    {
        while (xy[1] < mlx->height)
        {
            if (sphere_intersection(
                rays[xy[0] * mlx->height + xy[1]],
                &scene->element_list.elements[0],
                0))
            {
                mlx_put_pixel(scene->img, xy[0], xy[1], 0xFFFFFFFF);
            }
            else
                mlx_put_pixel(scene->img, xy[0], xy[1], 0x000000FF);
            xy[1]++;
        }
        xy[1] = 0;
        xy[0]++;
    }
    free(rays);
}

void do_ray_trace(t_scene scene, mlx_t *mlx, t_ray *rays, int xy[2])
{
	while (xy[0] < mlx->width)
	{
		while (xy[1] < mlx->height)
		{
			//TODO: Hacerlo con cada una de las figuras
			if (sphere_intersection( //Actualmente esto lo que hace es que si interseca pinta de blanco, si no, pues de negro
				rays[xy[0] * mlx->height + xy[1]],
				&scene.element_list.elements[0],
				0 ))
			{
				mlx_put_pixel(scene.img, xy[0], xy[1], 0xFFFFFFFF);
			}
			else
				mlx_put_pixel(scene.img, xy[0], xy[1], 0x000000FF);
			xy[1]++;
		}
		xy[1] = 0;
		xy[0]++;
	}
}

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
	do_ray_trace(scene, mlx, rays, xy);
	scene.mlx = mlx;
	mlx_loop_hook(mlx, key_hook, &scene);
	mlx_image_to_window(mlx, scene.img, 0, 0);
	mlx_loop(mlx);
	mlx_delete_image(mlx, scene.img);
	mlx_terminate(mlx);
	free_scene(&scene);
	free(rays);
	
	return (0);
}
