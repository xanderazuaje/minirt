/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_controls.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:08:45 by xazuaje-          #+#    #+#             */
/*   Updated: 2025/01/25 17:42:23 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_CONTROLS_H
#define CAMERA_CONTROLS_H
#define MOVE_SPEED 0.5f
#define ROTATION_SPEED 5.0f
#include "types.h"
#include "stdlib.h"
#include "rays.h"

void camera_controls(void *param);

#endif //CAMERA_CONTROLS_H
