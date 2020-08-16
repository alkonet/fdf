/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <gloggins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:11:48 by gloggins          #+#    #+#             */
/*   Updated: 2019/09/23 19:05:52 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

void	fdf(t_fdf *parse)
{
	if (parser(parse) == -1)
	{
		ft_putendl("Error");
		return ;
	}
	mlx(parse);
}

int		main(int ac, char **av)
{
	t_fdf	mine;

	if (ac == 2)
	{
		mine.name = av[1];
		mine.fd = open(mine.name, O_RDONLY);
		fdf(&mine);
	}
	else
		ft_putendl("Input incorrect \nUsage: ./fdf filename");
	return (0);
}
