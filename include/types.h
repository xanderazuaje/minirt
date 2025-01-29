/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:42:36 by xazuaje-          #+#    #+#             */
/*   Updated: 2025/01/07 11:07:59 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H
# include <sys/types.h>
# include "../lib/mlx/include/MLX42/MLX42.h"
typedef struct s_quaternion {
	double w;
	double x;
	double y;
	double z;
} t_quat;

typedef struct s_rgba
{
	u_int8_t	r;
	u_int8_t	g;
	u_int8_t	b;
	u_int8_t	a;
}	t_rgba;

typedef struct s_ambient_light
{
	double	light_ratio;
	t_rgba	rgba;
}	t_ambient_light;

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct s_camera
{
	t_vec3	coords;
	t_quat rotation;
	float	fov;
}	t_camera;

typedef struct s_focal_light
{
	t_vec3	coords;
	double	bright;
	t_rgba	rgba;
}	t_focal_light;

typedef struct s_sphere
{
	t_vec3	coords;
	double	diameter;
	double	radius;
	t_rgba	rgba;
}	t_sphere;

typedef struct s_plane
{
	t_vec3	coords;
	t_vec3	rotate_vec;
	double	module;
	t_rgba	rgba;
}	t_plane;

typedef struct s_cylinder
{
	t_vec3	coords;
	t_vec3	rotate_vec;
	double	module;
	double	diameter;
	double	height;
	t_rgba	rgba;
}	t_cylinder;

typedef enum e_element_type
{
	SPHERE,
	PLANE,
	CYLINDER
}	t_element_type;

typedef union u_scene_element
{
	t_sphere	sphere;
	t_plane		plane;
	t_cylinder	cylinder;
}	t_scene_element;

typedef struct s_ray {
	t_rgba rgba;
	t_vec3 direction;
	t_vec3 position;
	t_vec3 normalized;
} t_ray;

typedef struct s_element_list
{
	t_element_type	*types;
	t_scene_element	*elements;
	int (**func)(t_ray, t_scene_element *, int);

}	t_element_list;

typedef struct s_scene
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	int8_t			camera_count;
	t_camera		*cameras;
	int8_t			camera_idx;
	t_ambient_light	ambient_light;
	int8_t			lights_count;
	t_focal_light	*lights;
	int8_t			element_count;
	t_element_list	element_list;
}	t_scene;


#endif //TYPESH
