/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgba.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 19:02:12 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/12/01 19:02:38 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

int parse_rgba(char *rgba, int ln_nb, t_rgba *dest)
{
	t_splitted *params;

	params = ft_split(rgba, ',');
	if (params->len != 3)
	{
		ft_putstr_fd("bad rgb format at line ", 2);
		ft_putnbr_fd(ln_nb, 2);
		write(2, "\n", 1);
		free_splitted(&params);
		return (0);
	}
	dest->r = (int8_t)ft_atoi(params->string[0]);
	dest->g = (int8_t)ft_atoi(params->string[1]);
	dest->b = (int8_t)ft_atoi(params->string[2]);
	dest->a = (int8_t)0xFF;
	free_splitted(&params);
	return (1);
}

