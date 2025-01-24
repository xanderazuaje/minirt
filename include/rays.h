/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:29:45 by xazuaje-          #+#    #+#             */
/*   Updated: 2025/01/24 14:32:00 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by xander on 1/24/25.
//

#ifndef RAYS_H
#define RAYS_H

#include "types.h"
#include "vec3_operations.h"
#include "minirt.h"

t_ray init_ray(t_camera camera, const int coords[2]);
t_ray	*set_rays(t_camera camera, mlx_t *mlx);

#endif //RAYS_H
