/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:15:41 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/12/01 19:15:43 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <libft.h>
# include <types.h>
# include <vec3_operations.h>
#include <fcntl.h>

typedef enum e_elem_to_parse{
	ambient_light,
	camera,
	focal_light,
	sphere,
	plane,
	cylinder
} t_elem_to_parse;

void	initial_check(int argc, char **argv);
int		parse_line(t_splitted *tokens, t_scene *scene, int line_count);
int		parse_cylinder(t_splitted *tokens, int line_count, t_scene *scene);
int		parse_plane(t_splitted *tokens, int line_count, t_scene *scene);
int		parse_sphere(t_splitted *tokens, int line_count, t_scene *scene);
int		parse_focal_light(t_splitted *tokens, int line_count, t_scene *scene);
int		parse_camera(t_splitted *tokens, int line_count, t_scene *scene);
int		parse_ambience_light(t_splitted *tokens, int line_count, t_scene *scene);
void	store_element(t_scene *scene, t_scene_element scene_element, t_element_type type);
int		parse_vector(char *vec_str, int ln_nb, t_vec3 *dest);
int		parse_rgba(char *rgba, int ln_nb, t_rgba *dest);
void	parse_rt_file(char *file, t_scene *scene);
t_elem_to_parse get_token_val(t_splitted *lines, int line_count);
#endif
