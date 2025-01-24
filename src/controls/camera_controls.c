#include <camera_controls.h>

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
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

void camera_controls(void *param)
{
    t_scene *scene;
    mlx_t *mlx;
    t_ray *rays;
    int xy[2] = {0, 0};

    scene = ((t_scene *)param);
    mlx = scene->mlx;
    move_camera(scene, mlx);
    rays = set_rays(scene->cameras[0], mlx);
    while (xy[0] < mlx->width)
    {
        while (xy[1] < mlx->height)
        {
			if (scene->element_list.func[0](
				rays[xy[0] * mlx->height + xy[1]],
				&scene->element_list.elements[0],
				0 ))
                mlx_put_pixel(scene->img, xy[0], xy[1], 0xFFFFFFFF);
            else
                mlx_put_pixel(scene->img, xy[0], xy[1], 0x000000FF);
            xy[1]++;
        }
        xy[1] = 0;
        xy[0]++;
    }
    free(rays);
}
