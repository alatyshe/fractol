/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 18:26:31 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/12 18:26:32 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

#include <stdlib.h>
#include <stdio.h>
// #include <conio.h>
#include <math.h>
 

int				ft_key_control(int key, t_window *win)
{
	if (key == 53)
		exit(1);
	mlx_clear_window(win->mlx, win->win);
	return (0);
}

int			rgbtoint(int r, int g, int b)
{
	int			color;

	color = 0;
	color = b | (g << 8) | (r << 16);
	return (color);
}

void		display_mandelbrot(t_window *win)
{
	float	zi;
	float	zr;
	float	ci;
	float	cr;
	float	tmp;

	int		x;
 	int		y;
 	int		k;
 	int		m;

 	int color;


	for(x = -400; x < 400; x++)					//  проходим по всем пикселям оси х
	{
		ci = ((float)x) / 160.0;				//  присваеваем мнимой части с - i/160
		for(y = -200; y < 200; y++)				//  проходим по всем пикселям оси y
		{
			cr = ((float)y) / 120.0;			//  присваеваем вещественной части с - j/120
			zi = zr = 0.0;						//  присваеваем вещественной и мнимой части z - 0
			for(k = 0; k < DEPTH; k++)			//  вычисляем множество Мандельброта
			{
				tmp = zr * zr - zi * zi;
				zi = 2 * zr * zi + ci;
				zr = tmp + cr;
				if (zr * zr + zi * zi > 1.0E16)		//  если |z| слишком велико, то
					break;						//  выход из цикла
			}
			if (k < DEPTH)					//  |z| - велико
			{
				m = k % 8 + 1;				//  - это внешняя точка
				// setpallette(m, m * 8 + 7, 0, 0);	// выбираем оттенок
				// putpixel(x + 160, y + 190, m);	// красного

				color = rgbtoint(m, m * 8 + 7, 0);
				mlx_pixel_put(win->mlx, win->win, x + 400, y + 200, color);
			}
			else
				mlx_pixel_put(win->mlx, win->win, x + 400, y + 200, 0);
		}
	}
	mlx_hook(win->win, 2, 5, ft_key_control, win);
	mlx_loop(win->mlx);
}