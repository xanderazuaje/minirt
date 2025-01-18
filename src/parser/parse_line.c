/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:16:54 by xazuaje-          #+#    #+#             */
/*   Updated: 2025/01/04 15:36:31 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void initial_check(int argc, char **argv)
{
	if (argc != 2)
	{
		write(2, "invalid arguments\n", 18);
		exit( 1);
	}
	if (ft_strnstr(argv[1], ".rt\0", ft_strlen(argv[1])) == 0)
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

int parse_line(t_splitted *tokens, t_scene *scene, int line_count)
{
	t_elem_to_parse elem_to_parse;

	elem_to_parse = get_token_val(tokens, line_count);
	if (elem_to_parse == invalid)
		return (0);
	if (elem_to_parse == ambient_light)
		return parse_ambience_light(tokens, line_count, scene);
	if (elem_to_parse == camera)
		return parse_camera(tokens, line_count, scene);
	if (elem_to_parse == focal_light)
		return parse_focal_light(tokens, line_count, scene);
	if (elem_to_parse == sphere)
		return parse_sphere(tokens, line_count, scene);
	if (elem_to_parse == plane)
		return parse_plane(tokens, line_count, scene);
	return parse_cylinder(tokens, line_count, scene);
}
