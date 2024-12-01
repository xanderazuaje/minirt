/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 19:03:41 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/12/01 19:04:01 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <parser.h>

void store_element(t_scene *scene, t_scene_element scene_element, t_element_type type)
{
	size_t size;
	size_t cursize;

	scene->element_count++;
	cursize = sizeof(t_scene_element) * (scene->element_count - 1);
	size = sizeof(t_scene_element) * scene->element_count;
	scene->element_list.elements = (t_scene_element*)ft_realloc(scene->element_list.elements, cursize, size);
	scene->element_list.elements[scene->element_count - 1] = scene_element;
	cursize = sizeof(t_element_type) * (scene->element_count - 1);
	size = sizeof(t_element_type) * scene->element_count;
	scene->element_list.types = (t_element_type *)ft_realloc(scene->element_list.types, cursize, size);
	scene->element_list.types[scene->element_count - 1] = type;
}
