/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 21:00:41 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/12/17 21:57:02 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <intersection.h>

short cylinder_intersection(t_ray ray, t_scene_element *elem, int bounce)
{
	t_cylinder *c;
	c = &elem->cylinder;
	(void)bounce;

	return 0;
}
