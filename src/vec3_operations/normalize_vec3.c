/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_vec3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:08:17 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/12/09 14:22:14 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vec3_operations.h>

t_vec3	normalize_vec3(t_vec3 vec, double module)
{
	if (module == 0)
	{
		return (t_vec3{0, 0, 0});
	}
	return (t_vec3{
			vec.x / module,
			vec.y / module,
			vec.z / module
		});
}
