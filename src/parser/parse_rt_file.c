/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 19:14:12 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/12/01 19:15:26 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void syntax_error(int line_count)
{
	ft_putstr_fd("invalid syntax at line: ", 2);
	ft_putnbr_fd(line_count, 2);
	write(2, "\n", 1);
	exit(1);
}

void parse_rt_file(char *file, t_scene *scene)
{
	int line_count;
	int fd;
	char *ln;
	t_splitted *lines;

	fd = open(file, O_RDONLY);
	line_count = 0;
	if (fd < 0)
	{
		perror(file);
		exit(1);
	}
	while (1)
	{
		ln = get_next_line(fd);
		if (!ln)
			return ((void) close(fd));
		line_count++;
		if (ft_strlen(ln) == 0)
			return (syntax_error(line_count));
		lines = ft_split(ln, ' ');
		if (!parse_line(lines, scene, line_count))
			return (free(ln), free_splitted(&lines), (void) close(fd));
		free_splitted(&lines);
		free(ln);
	}
}

