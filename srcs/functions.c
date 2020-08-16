/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <gloggins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:11:48 by gloggins          #+#    #+#             */
/*   Updated: 2019/09/23 19:05:52 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		zoom(int keycode, t_fdf *key)
{
	if (keycode == 69 && key->sx * 2 <= 10000 && key->sy * 2 <= 10000)
	{
		mlx_clear_window(key->mlx, key->win);
		key->sx *= 2;
		key->sy *= 2;
		key->z *= 2;
		draw(key);
	}
	if (keycode == 78 && key->sx * 0.5 >= 1 && key->sy * 0.5 >= 1 &&
		(-key->z * 0.5 >= 1 || key->z * 0.5 >= 1))
	{
		mlx_clear_window(key->mlx, key->win);
		key->sx *= 0.5;
		key->sy *= 0.5;
		key->z *= 0.5;
		draw(key);
	}
}

int			cross(void)
{
	exit(0);
	return (0);
}

void		move(int keycode, t_fdf *key)
{
	if ((keycode >= 123 && keycode <= 126) || keycode == 15)
	{
		mlx_clear_window(key->mlx, key->win);
		if (keycode == LEFT)
			key->dx += 10;
		if (keycode == RIGHT)
			key->dx -= 10;
		if (keycode == UP)
			key->dy -= 10;
		if (keycode == DOWN)
			key->dy += 10;
		if (keycode == 15)
			key->check = 0;
		draw(key);
	}
}

int			keyboard(int keycode, t_fdf *key)
{
	move(keycode, key);
	zoom(keycode, key);
	if (keycode == 67)
	{
		mlx_clear_window(key->mlx, key->win);
		key->z++;
		draw(key);
	}
	if (keycode == 75)
	{
		mlx_clear_window(key->mlx, key->win);
		key->z--;
		draw(key);
	}
	if (keycode == 8)
	{
		mlx_clear_window(key->mlx, key->win);
		if (key->check % 11 == 0)
			key->color = 0xFF000000;
		key->color = key->color >> 2;
		draw(key);
	}
	if (keycode == EXIT)
		cross();
	return (0);
}

void		mlx(t_fdf *key)
{
	key->check = 0;
	key->mlx = mlx_init();
	key->win = mlx_new_window(key->mlx, WIDTH, HEIGHT, "fdf");
	draw(key);
	mlx_key_hook(key->win, keyboard, key);
	mlx_hook(key->win, 17, (1L << 17), cross, key);
	mlx_loop(key->mlx);
}
