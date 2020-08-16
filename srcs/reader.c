/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <gloggins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:11:48 by gloggins          #+#    #+#             */
/*   Updated: 2019/09/23 19:05:52 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			all_tab(t_fdf *parse, char *line)
{
	int		x;
	char	**tab;

	x = 0;
	tab = ft_strsplit(line, ' ');
	while (tab[x])
	{
		free(tab[x]);
		x++;
	}
	if (parse->lines == 0)
		parse->chars = x;
	else
	{
		if (x != parse->chars)
			return (-1);
	}
	free(line);
	free(tab);
	parse->lines++;
	return (0);
}

int			loc_tab(t_fdf *parse)
{
	char	*line;
	int		reader;

	line = NULL;
	parse->lines = 0;
	parse->chars = 0;
	while ((reader = get_next_line(parse->fd, &line)) > 0)
	{
		if (all_tab(parse, line) == -1)
			return (-1);
	}
	parse->map = ft_memalloc(sizeof(int*) * parse->lines);
	close(parse->fd);
	parse->fd = open(parse->name, O_RDONLY);
	return (0);
}

int			parser(t_fdf *parse)
{
	char	*line;
	char	**tab;
	int		xytab[3];

	xytab[1] = 0;
	if (loc_tab(parse) == -1)
		return (-1);
	while ((xytab[2] = get_next_line(parse->fd, &line)) > 0)
	{
		xytab[0] = 0;
		tab = ft_strsplit(line, ' ');
		parse->map[xytab[1]] = ft_memalloc(sizeof(int) * parse->chars);
		while (tab[xytab[0]] != NULL)
		{
			parse->map[xytab[1]][xytab[0]] = ft_atoi(tab[xytab[0]]);
			free(tab[xytab[0]]);
			xytab[0]++;
		}
		free(tab);
		xytab[1]++;
	}
	return ((xytab[2] == -1) ? -1 : 0);
}
