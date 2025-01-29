/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 21:20:39 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/12/28 23:15:51 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H
# include "types.h"
# include "vec3_operations.h"

int sphere_intersection(t_ray ray, t_scene_element *elem, int bounce);
int plane_intersection(t_ray ray, t_scene_element *elem, int bounce);
int cylinder_intersection(t_ray ray, t_scene_element *elem, int bounce);
#endif //INTERSECTION_H
