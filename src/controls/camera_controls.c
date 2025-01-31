/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:08:17 by xazuaje-          #+#    #+#             */
/*   Updated: 2025/01/25 17:38:20 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <camera_controls.h>
#include <quaternion_operations.h>
#define M_PI 3.14159265358979323846

void rotate_camera(t_quat *rotation, double angle, t_vec3 axis)
{
    double half_angle;
    double sin_half_angle;

    half_angle = angle / 2.0;
    sin_half_angle = sin(half_angle * ( M_PI / 180));
    *rotation = multiply_quaternion(*rotation, (t_quat){
        .w = cos(half_angle),
        .x = axis.x * sin_half_angle,
        .y = axis.y * sin_half_angle,
        .z = axis.z * sin_half_angle,
    });
}

void move_camera(t_scene *scene, mlx_t *mlx)
{
    if (mlx_is_key_down(mlx, MLX_KEY_UP))
        scene->cameras[0].coords.z += MOVE_SPEED;
    if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
        scene->cameras[0].coords.z -= MOVE_SPEED;
    if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
        scene->cameras[0].coords.x += MOVE_SPEED;
    if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
        scene->cameras[0].coords.x -= MOVE_SPEED;
    if (mlx_is_key_down(mlx, MLX_KEY_J))
        scene->cameras[0].coords.y += MOVE_SPEED;
    if (mlx_is_key_down(mlx, MLX_KEY_K))
        scene->cameras[0].coords.y -= MOVE_SPEED;
    if (mlx_is_key_down(mlx, MLX_KEY_KP_8))
        rotate_camera(&scene->cameras[0].rotation, -ROTATION_SPEED, (t_vec3){1.0, 0.0, 0.0}); // Rotar hacia arriba
    if (mlx_is_key_down(mlx, MLX_KEY_KP_2))
        rotate_camera(&scene->cameras[0].rotation, ROTATION_SPEED, (t_vec3){1.0, 0.0, 0.0}); // Rotar hacia abajo
    if (mlx_is_key_down(mlx, MLX_KEY_KP_4))
        rotate_camera(&scene->cameras[0].rotation, ROTATION_SPEED, (t_vec3){0.0, 1.0, 0.0}); // Rotar hacia la izquierda
    if (mlx_is_key_down(mlx, MLX_KEY_KP_6))
        rotate_camera(&scene->cameras[0].rotation, -ROTATION_SPEED, (t_vec3){0.0, 1.0, 0.0}); // Rotar hacia la derecha
    if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
        mlx_close_window(mlx);
}

void camera_controls(void *param)
{
    t_scene *scene;
    mlx_t *mlx;
    t_ray *rays;
    int xy[2] = {0, 0};
    int8_t i = 0;
    int8_t j = 0;

    xy[0] = 0;
    xy[1] = 0;
    scene = ((t_scene *)param);
    mlx = scene->mlx;
    move_camera(scene, mlx);
    rays = set_rays(scene->cameras[0], mlx);
    while (xy[0] < mlx->width)
    {
        while (xy[1] < mlx->height)
        {
            i = scene->element_count - 1;
            j = 0;
            while (i >= 0)
            {
			    if (scene->element_list.func[i](
				    rays[xy[0] * mlx->height + xy[1]],
				    &scene->element_list.elements[0],
				    0 ))
                {
                    int p = 0xFFFFFFFF;
                    mlx_put_pixel(scene->img, xy[0], xy[1], p);
                    j = 1;
                }
                i--;
            }
            if (j == 0)
                mlx_put_pixel(scene->img, xy[0], xy[1], 0x000000FF);
            xy[1]++;
        }
        xy[1] = 0;
        xy[0]++;
    }
    free(rays);
}
