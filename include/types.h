/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:42:36 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/11/25 18:54:55 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
#define TYPES_H
typedef struct s_rgba {
	int8_t r;
	int8_t g;
	int8_t b;
	int8_t a;
} t_rgba;

typedef struct s_ambient_light {
	double light_ratio;
	t_rgba rgba;
} t_ambient_light;

typedef struct s_vec3 {
	double x;
	double y;
	double z;
} t_vec3;

typedef struct s_camera {
	t_vec3 coords;
	t_vec3 orientation;
	int8_t fov;
} t_camera;

typedef struct s_focal_light {
	t_vec3 coords;
	double bright;
	t_rgba rgba;
} t_focal_light;

typedef struct s_sphere {
	t_vec3 coords;
	double diameter;
	t_rgba rgba;
} t_sphere;

typedef struct s_plane {
	t_vec3 coords;
	t_vec3 rotate_vec;
	t_rgba rgba;
} t_plane;

typedef struct s_cylinder {
	t_vec3 coords;
	t_vec3 rotate_vec;
	double diameter;
	double height;
	t_rgba rgba;
} t_cylinder;

typedef enum e_element_type {
	SPHERE,
	PLANE,
	CYLINDER
} t_element_type;

typedef union u_scene_element{
	t_ambient_light ambient_light;
	t_camera camera;
	t_focal_light focal_light;
	t_sphere sphere;
	t_plane plane;
	t_cylinder cylinder;
} t_scene_element;

typedef struct s_element_list {
	t_element_type *types;
	t_scene_element *elements;
} t_element_list;

typedef struct s_scene {
	t_camera *cameras;
	t_camera *curr_camera;
	t_ambient_light ambient_light;
	t_focal_light *lights;
	t_element_list element_list;
} t_scene;

#endif //TYPES_H
