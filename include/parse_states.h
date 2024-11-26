/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_states.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:58:25 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/11/24 21:07:39 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_STATES_H
# define PARSE_STATES_H

typedef enum e_elem_to_parse{
	ambient_light,
	camera,
	focal_light,
	sphere,
	plane,
	cylinder
} t_elem_to_parse;

#endif //PARSE_STATES_H
