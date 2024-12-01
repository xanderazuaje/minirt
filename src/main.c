/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 09:04:35 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/12/01 19:16:48 by xazuaje-         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_scene scene;

	scene.element_list.elements = NULL;
	scene.element_count = 0;
	scene.camera_count = 0;
	scene.lights_count = 0;
	initial_check(argc, argv);
	parse_rt_file(argv[1], &scene);
	free_scene(&scene);
	return (0);
}
