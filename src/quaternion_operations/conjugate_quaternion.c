/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conjugate_quaternion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 02:57:56 by xazuaje-          #+#    #+#             */
/*   Updated: 2025/01/05 17:58:16 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <quaternion_operations.h>

t_quat	conj_quaternion(const t_quat q)
{
	return ((t_quat){q.w, -q.x, -q.y, -q.z});
}
