/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 21:00:28 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/12/28 23:17:56 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <intersection.h>

short plane_intersection(t_ray ray, t_scene_element *elem, int bounce)
{
	t_plane *p;
	p = &elem->plane;
	(void)bounce;
	(void)ray;

	return 0;
}
