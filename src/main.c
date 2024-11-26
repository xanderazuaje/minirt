/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 09:04:35 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/11/26 15:21:48 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by xander on 11/24/24.
//

#include <minirt.h>
#include <types.h>
#include <parse_states.h>

void initial_check(int argc, char **argv)
{
	if (argc != 2)
	{
		write(2, "invalid arguments\n", 18);
		exit( 1);
	}
	if (ft_strnstr(argv[1], ".rt\0", strlen(argv[1])) == 0)
	{
		write(2, "file must end with .rt\n", 23);
		exit( 1);
	}
}

t_elem_to_parse get_token_val(t_splitted *lines, int line_count)
{
	if (ft_strncmp(lines->string[0], "A", 2) == 0)
		return ambient_light;
	if (ft_strncmp(lines->string[0], "C", 2) == 0)
		return camera;
	if (ft_strncmp(lines->string[0], "L", 2) == 0)
		return focal_light;
	if (ft_strncmp(lines->string[0], "sp", 3) == 0)
		return sphere;
	if (ft_strncmp(lines->string[0], "pl", 3) == 0)
		return plane;
	if (ft_strncmp(lines->string[0], "cy", 3) == 0)
		return cylinder;
	ft_putstr_fd("at line: ", 2);
	ft_putnbr_fd(line_count, 2);
	ft_putstr_fd(" unknown token <", 2);
	ft_putstr_fd(lines->string[0], 2);
	ft_putendl_fd(">", 2);
	return -1;
}

int parse_rgba(char *rgba, int ln_nb, t_rgba *dest)
{
	t_splitted *params;

	params = ft_split(rgba, ',');
	if (params->len != 3)
	{
		ft_putstr_fd("bad rgb format at line ", 2);
		ft_putnbr_fd(ln_nb, 2);
		write(2, "\n", 1);
		free_splitted(&params);
		return (0);
	}
	dest->r = (int8_t)ft_atoi(params->string[0]);
	dest->g = (int8_t)ft_atoi(params->string[1]);
	dest->b = (int8_t)ft_atoi(params->string[2]);
	dest->a = (int8_t)0xFF;
	free_splitted(&params);
	return (1);
}

int parse_vector(char *vec_str, int ln_nb, t_vec3 *dest)
{
	t_splitted *params;

	params = ft_split(vec_str, ',');
	if (params->len != 3)
	{
		ft_putstr_fd("bad vec3 format at line ", 2);
		ft_putnbr_fd(ln_nb, 2);
		write(2, "\n", 1);
		free_splitted(&params);
		return (0);
	}
	dest->x = (int8_t)ft_atof(params->string[0]);
	dest->y = (int8_t)ft_atof(params->string[1]);
	dest->z = (int8_t)ft_atof(params->string[2]);
	free_splitted(&params);
	return (1);
}

int parse_ambience_light(t_splitted *tokens, t_scene *scene, int line_count, t_scene_element *scene_element, t_rgba rgba)
{
	if (tokens->len != 3)
	{
		ft_putstr_fd("bad ambience light parameters at line ", 2);
		ft_putnbr_fd(line_count, 2);
		write(2, "\n", 1);
		return (0);
	}
	scene_element->ambient_light.light_ratio = ft_atof(tokens->string[1]);
	parse_rgba(tokens->string[2], line_count, &rgba);
	scene_element->ambient_light.rgba = rgba;
	scene->ambient_light = scene_element->ambient_light;
	return (1);
}

int parse_camera(t_splitted *tokens, int line_count, t_scene_element *scene_element, t_vec3 vec3)
{
	if (tokens->len != 4)
	{
		ft_putstr_fd("bad camera parameters at line ", 2);
		ft_putnbr_fd(line_count, 2);
		write(2, "\n", 1);
		return (0);
	}
	parse_vector(tokens->string[1], line_count, &vec3);
	scene_element->camera.coords = vec3;
	parse_vector(tokens->string[2], line_count, &vec3);
	scene_element->camera.orientation = vec3;
	scene_element->camera.fov = (int8_t)ft_atoi(tokens->string[3]);
	return (1);
}

int parse_focal_light(t_splitted *tokens, int line_count, t_scene_element *scene_element, t_rgba rgba, t_vec3 vec3)
{
	if (tokens->len != 4)
	{
		ft_putstr_fd("bad light parameters at line ", 2);
		ft_putnbr_fd(line_count, 2);
		write(2, "\n", 1);
		return (0);
	}
	parse_vector(tokens->string[1], line_count, &vec3);
	scene_element->focal_light.coords = vec3;
	scene_element->focal_light.bright = (int8_t)ft_atoi(tokens->string[2]);
	parse_rgba(tokens->string[3], line_count, &rgba);
	scene_element->focal_light.rgba = rgba;
	return (1);
}

int parse_sphere(t_splitted *tokens, int line_count, t_scene_element *scene_element, t_rgba rgba, t_vec3 vec3)
{
	if (tokens->len != 4)
	{
		ft_putstr_fd("bad sphere parameters at line ", 2);
		ft_putnbr_fd(line_count, 2);
		write(2, "\n", 1);
		return (0);
	}
	parse_vector(tokens->string[1], line_count, &vec3);
	scene_element->sphere.coords = vec3;
	scene_element->sphere.diameter = (int8_t)ft_atof(tokens->string[2]);
	parse_rgba(tokens->string[3], line_count, &rgba);
	scene_element->sphere.rgba = rgba;
	return (1);
}

int parse_plane(t_splitted *tokens, int line_count, t_scene_element *scene_element, t_rgba rgba, t_vec3 vec3)
{
	if (tokens->len != 4)
	{
		ft_putstr_fd("bad plane parameters at line ", 2);
		ft_putnbr_fd(line_count, 2);
		write(2, "\n", 1);
		return (0);
	}
	parse_vector(tokens->string[1], line_count, &vec3);
	scene_element->plane.coords = vec3;
	parse_vector(tokens->string[2], line_count, &vec3);
	scene_element->plane.rotate_vec = vec3;
	parse_rgba(tokens->string[3], line_count, &rgba);
	scene_element->plane.rgba = rgba;
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
	scene_element.cylinder.diameter = (int8_t)ft_atof(tokens->string[3]);
	scene_element.cylinder.height = (int8_t)ft_atof(tokens->string[4]);
	parse_rgba(tokens->string[5], line_count, &rgba);
	scene_element.cylinder.rgba = rgba;
	return (1);
}

int parse_line(t_splitted *tokens, t_scene *scene, int line_count)
{
	t_elem_to_parse elem_to_parse;
	t_scene_element scene_element;
	t_rgba rgba;
	t_vec3 vec3;

	elem_to_parse = get_token_val(tokens, line_count);
	if (elem_to_parse == -1)
		return (0);
	if (elem_to_parse == ambient_light)
		return parse_ambience_light(tokens, scene, line_count, &scene_element, rgba);
	if (elem_to_parse == camera)
		return parse_camera(tokens, line_count, &scene_element, vec3);
	if (elem_to_parse == focal_light)
		return parse_focal_light(tokens, line_count, &scene_element, rgba, vec3);
	if (elem_to_parse == sphere)
		return parse_sphere(tokens, line_count, &scene_element, rgba, vec3);
	if (elem_to_parse == plane)
		return parse_plane(tokens, line_count, &scene_element, rgba, vec3);
	return parse_cylinder(tokens, line_count, scene);
}

int	main(int argc, char **argv)
{
	int fd;
	char *ln;
	t_splitted *lines;
	t_scene scene;
	int line_count;

	scene.element_list.elements = NULL;
	initial_check(argc, argv);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror(argv[1]);
		exit(1);
	}
	line_count = 0;
	while (1)
	{
		ln = get_next_line(fd);
		if (!ln)
		{
			close(fd);
			break;
		}
		line_count++;
		if (strlen(ln) == 0)
		{
			ft_putstr_fd("invalid syntax at line: ", 2);
			ft_putnbr_fd(line_count, 2);
			write(2, "\n", 1);
			exit(1);
		}
		lines = ft_split(ln, ' ');
		if (!parse_line(lines, &scene, line_count))
		{
			free(ln);
			free_splitted(&lines);
			close(fd);
			break;
		}
		free_splitted(&lines);
		free(ln);
	}
	return (0);
}