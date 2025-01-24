/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:29:39 by xazuaje-          #+#    #+#             */
/*   Updated: 2025/01/24 14:30:38 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rays.h>

t_ray	*set_rays(t_camera camera, mlx_t *mlx)
{
	int		xy[2];
	t_ray	*rays;

	rays = (t_ray *)safe_malloc(sizeof(t_ray) * mlx->width * mlx->height);/*rayo x pto del mapa*/
	xy[0] = 0;
	while (xy[0] < mlx->width)
	{
		xy[1] = 0;
		while (xy[1] < mlx->height)
		{
			rays[xy[0] * mlx->height + xy[1]] = init_ray(camera, xy);/*se inicializa el rayo en cada pto del mapa*/
			xy[1]++;
		}
		xy[0]++;
	}
	return (rays);
}


