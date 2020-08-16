/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <gloggins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:11:48 by gloggins          #+#    #+#             */
/*   Updated: 2019/09/23 19:05:52 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <../minilibx_macos/mlx.h>
# include <math.h>
# include "../libft/includes/libft.h"
# define WIDTH 1920
# define HEIGHT 1080
# define DOWN	126
# define UP		125
# define RIGHT	124
# define LEFT	123
# define EXIT	53
# define WHITE 0x00FFFFFF

typedef struct		s_fdf
{
	int				fd;
	char			*name;
	void			*mlx;
	void			*win;
	int				**map;
	int				lines;
	int				check;
	int				chars;
	int				z;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	unsigned long	color;
}					t_fdf;

void	draw(t_fdf *draw);
void	draw_lines(t_fdf *draw, int x, int y);
void	draw_line(t_fdf *draw, int *tabxy, int x, int y);
void	mlx(t_fdf *key);
void	move(int keycode, t_fdf *key);
void	zoom(int keycode, t_fdf *key);
void	fdf(t_fdf *parse);
void	print_menu(t_fdf *fdf);
int		cross(void);
int		keyboard(int keycode, t_fdf *key);
int		parser(t_fdf *parse);
int		loc_tab(t_fdf *parse);
int		all_tab(t_fdf *parse, char *line);

#endif
