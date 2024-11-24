/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 09:04:35 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/11/24 10:36:26 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by xander on 11/24/24.
//

#include <minirt.h>

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "miniretarded", false);
	img = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!img || mlx_image_to_window(mlx, img, 0, 0) < 0)
		ft_error();
	mlx_put_pixel(img, 0, 0, 0xFF0000FF);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
