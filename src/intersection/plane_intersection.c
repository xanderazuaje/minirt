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
    (void)bounce;
    p = &elem->plane;

    t_vec3  origin_less_pplane = substract_vec3(ray.position, p->coords);
    float   origin_less_plane_o_normal = dot_product_vec3(origin_less_pplane, p->rotate_vec);
    float   dir_o_normal = dot_product_vec3(ray.normalized, p->rotate_vec);

    if (dir_o_normal == 0)
        return (0);

    float   t = ((-1 * origin_less_plane_o_normal) / dir_o_normal);

    if (t < 0)
        return (0);

    t_vec3 p_intersection = add_vec3(ray.position, (t_vec3){t * ray.normalized.x, t * ray.normalized.y, t * ray.normalized.z});
    (void)p_intersection;
    return (1);
}
