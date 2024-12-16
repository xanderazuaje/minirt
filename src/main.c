/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 09:04:35 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/12/02 15:25:08 by xazuaje-         ###   ########.fr       */
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
	int x;
	int y;
	mlx_image_t *img;
	(void)camera;

	x = 0;
	y = 0;
	img = mlx_new_image(mlx, mlx->width, mlx->height);
	if (!img)
		return NULL;
	while (x < mlx->width)
	{
		while (y < mlx->height)
		{
			//print uv coordinates
			int real_x;
			int real_y;
			double uv_x = (double)(WIN_WIDTH - x) / WIN_WIDTH;
			double uv_y = (double)(WIN_HEIGHT - y) / WIN_HEIGHT;
			printf("x -> %f, y -> %f\n", uv_x, uv_y);
			t_rgba c1;
			c1.r = 0xFF * uv_x;
			c1.g = 0xFF * uv_y;
			c1.b = 0x00;
			c1.a = 0xFF;
			mlx_put_pixel(img, x, y, get_rgba(c1));
			y++;
		}
		y = 0;
		x++;
	}
	return img;
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
