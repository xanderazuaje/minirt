/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:59:47 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/12/29 18:00:01 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

int parse_sphere(t_splitted *tokens, int line_count, t_scene *scene)
{
	t_scene_element scene_element;
	t_rgba rgba;
	t_vec3 vec3;
	if (tokens->len != 4)
	{
		ft_putstr_fd("bad sphere parameters at line ", 2);
		ft_putnbr_fd(line_count, 2);
		write(2, "\n", 1);
		return (0);
	}
	parse_vector(tokens->string[1], line_count, &vec3);
	scene_element.sphere.coords = vec3;
	scene_element.sphere.diameter = ft_atof(tokens->string[2]);
	scene_element.sphere.radius = scene_element.sphere.diameter / 2;
	parse_rgba(tokens->string[3], line_count, &rgba);
	scene_element.sphere.rgba = rgba;
	store_element(scene, scene_element, SPHERE);
	return (1);
}

int parse_plane(t_splitted *tokens, int line_count, t_scene *scene)
{
	t_scene_element scene_element;
	t_rgba rgba;
	t_vec3 vec3;

	if (tokens->len != 4)
	{
		ft_putstr_fd("bad plane parameters at line ", 2);
		ft_putnbr_fd(line_count, 2);
		write(2, "\n", 1);
		return (0);
	}
	parse_vector(tokens->string[1], line_count, &vec3);
	scene_element.plane.coords = vec3;
	parse_vector(tokens->string[2], line_count, &vec3);
	scene_element.plane.rotate_vec = vec3;
	parse_rgba(tokens->string[3], line_count, &rgba);
	scene_element.plane.rgba = rgba;
	store_element(scene, scene_element, PLANE);
	return (1);
}


int parse_cylinder(t_splitted *tokens, int line_count, t_scene *scene)
{
	t_scene_element scene_element;
	t_rgba rgba;
	t_vec3 vec3;
	if (tokens->len != 6)
	{
		ft_putstr_fd("bad cylinder parameters at line ", 2);
		ft_putnbr_fd(line_count, 2);
		write(2, "\n", 1);
		return (0);
	}
	parse_vector(tokens->string[1], line_count, &vec3);
	scene_element.cylinder.coords = vec3;
	parse_vector(tokens->string[2], line_count, &vec3);
	scene_element.cylinder.rotate_vec = vec3;
	scene_element.cylinder.diameter = ft_atof(tokens->string[3]);
	scene_element.cylinder.height = ft_atof(tokens->string[4]);
	parse_rgba(tokens->string[5], line_count, &rgba);
	scene_element.cylinder.rgba = rgba;
	store_element(scene, scene_element, CYLINDER);
	return (1);
}
