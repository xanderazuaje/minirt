/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 19:02:57 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/12/09 14:18:12 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

int parse_vector(char *vec_str, int ln_nb, t_vec3 *dest)
{
	t_splitted *params;

	params = ft_split(vec_str, ',');
	if (params->len != 3)
	{
		ft_putstr_fd("bad vec3 format at line ", 2);
		ft_putnbr_fd(ln_nb, 2);
		write(2, "\n", 1);
		free_splitted(&params);
		return (0);
	}
	dest->x = (int8_t) ft_atof(params->string[0]);
	dest->y = (int8_t) ft_atof(params->string[1]);
	dest->z = (int8_t) ft_atof(params->string[2]);
	//printf("tokens string kdhfvkb: i %f j %f k %f\n", dest->x, dest->y, dest->z);
	free_splitted(&params);
	return (1);
}

