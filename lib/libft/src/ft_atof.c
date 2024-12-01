/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:41:57 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/11/30 13:23:49 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	parse_decimal(const char **s, double *a, int *e, unsigned char *c)
{
	while (*c != '\0' && ft_isdigit(*c))
	{
		*c = **s;
		*a = *a * 10.0 + (*c - '0');
		*e = *e - 1;
		(*s)++;
	}
}

double	ft_atof(const char *s)
{
	double			a;
	int				e;
	unsigned char	c;

	a = 0.0;
	e = 0;
	c = *s;
	while (c != '\0' && ft_isdigit(c))
	{
		c = *s;
		a = a * 10.0 + (c - '0');
		s++;
	}
	if (c == '.')
		parse_decimal(&s, &a, &e, &c);
	while (e < 0)
	{
		a *= 0.1;
		e++;
	}
	return (a);
}
