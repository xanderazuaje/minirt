/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_optics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 19:01:05 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/12/01 19:01:43 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

int parse_ambience_light(t_splitted *tokens, int line_count, t_scene *scene)
{
	t_scene_element scene_element;
	t_rgba rgba;

	if (tokens->len != 3)
	{
		ft_putstr_fd("bad ambience light parameters at line ", 2);
		ft_putnbr_fd(line_count, 2);
		write(2, "\n", 1);
		return (0);
	}
	scene_element.ambient_light.light_ratio = ft_atof(tokens->string[1]);
	parse_rgba(tokens->string[2], line_count, &rgba);
	scene_element.ambient_light.rgba = rgba;
	scene->ambient_light = scene_element.ambient_light;
	return (1);
}

int parse_camera(t_splitted *tokens, int line_count, t_scene *scene)
{
	t_camera camera;
	t_vec3 vec3;

	if (tokens->len != 4)
	{
		ft_putstr_fd("bad camera parameters at line ", 2);
		ft_putnbr_fd(line_count, 2);
		write(2, "\n", 1);
		return (0);
	}
	parse_vector(tokens->string[1], line_count, &vec3);
	camera.coords = vec3;
	parse_vector(tokens->string[2], line_count, &vec3);
	camera.orientation = vec3;
	camera.fov = (int8_t)ft_atoi(tokens->string[3]);
	scene->camera_count++;
	scene->cameras = (t_camera *)ft_realloc(scene->cameras, sizeof(t_camera) * (scene->camera_count - 1), sizeof(t_camera) * scene->camera_count);
	scene->cameras[scene->camera_count - 1] = camera;
	return (1);
}

int parse_focal_light(t_splitted *tokens, int line_count, t_scene *scene)
{
	t_focal_light focal_light;
	t_rgba rgba;
	t_vec3 vec3;
	if (tokens->len != 4)
	{
		ft_putstr_fd("bad light parameters at line ", 2);
		ft_putnbr_fd(line_count, 2);
		write(2, "\n", 1);
		return (0);
	}
	parse_vector(tokens->string[1], line_count, &vec3);
	focal_light.coords = vec3;
	focal_light.bright = (int8_t)ft_atoi(tokens->string[2]);
	parse_rgba(tokens->string[3], line_count, &rgba);
	focal_light.rgba = rgba;
	scene->lights_count++;
	scene->lights = (t_focal_light*)ft_realloc(scene->lights,sizeof(t_focal_light) * (scene->lights_count - 1), sizeof(t_focal_light) * scene->lights_count);
	scene->lights[scene->lights_count - 1] = focal_light;
	return (1);
}

