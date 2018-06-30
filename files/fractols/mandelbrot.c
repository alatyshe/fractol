/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 18:26:31 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/12 18:26:32 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/fractol.h"

#include <stdlib.h>
#include <stdio.h>
// #include <conio.h>
#include <math.h>

int			rgbtoint(int r, int g, int b)
{
	int			color;

	color = 0;
	color = b | (g << 8) | (r << 16);
	return (color);
}

void		display_mandelbrot(t_window *win)
{
	t_fract 	*fractol;

	fractol = win->fractol;

	float	tmp;

	int		x;
 	int		y;
 	int		k;
 	int		m;

 	int 	color;


 	x = -400;
 	// printf("WRITE FRACT\n");
	while (x < 400)							//  проходим по всем пикселям оси х
	{
		fractol->ci = ((float)x + fractol->indent_x) / 160.0;				//  присваеваем мнимой части с - i/160

		y = -400;
		while (y < 400)						//  проходим по всем пикселям оси y
		{
			fractol->cr = ((float)y + fractol->indent_y) / 140.0;			//  присваеваем вещественной части с - j/120
			
			fractol->pi = 0.0;							//  присваеваем вещественной и мнимой части z - 0
			fractol->pr = 0.0;

			k = 0;
			while (k < DEPTH)							//  вычисляем множество Мандельброта
			{
				tmp = fractol->pr * fractol->pr - fractol->pi * fractol->pi;
				fractol->pi = (2 * fractol->pr * fractol->pi + fractol->ci) * fractol->zoom_z;
				fractol->pr = (tmp + fractol->cr) * fractol->zoom_z;
				if (fractol->pr * fractol->pr + fractol->pi * fractol->pi > 500)		//  если |z| слишком велико, то
					break;								//  выход из цикла

				k++;
			}


			if (k < DEPTH)								//  |z| - велико
			{
				m = k % 8 + 1;							//  - это внешняя точка
				color = rgbtoint(m, m * 8 + 7, 0);

				mlx_pixel_put(win->mlx, win->win, x + 400, y + 400, color);
			}
			else
				mlx_pixel_put(win->mlx, win->win, x + 400, y + 400, 0);

			y++;
		}
		x++;
	}
	
}


// PR = 1.5 * (X - WIDTH / 2) / (0.5 * ZOOM * WIDTH) + X_MOVE_M;
// PI = (Y - HEIGHT / 2) / (0.5 * ZOOM * HEIGHT) + Y_MOVE_M;
// set_variables_zero(info);
// info->fractal_v->i = -1;
// while (++info->fractal_v->i < DEPTH)
// {
// 	OLDRE = NEWRE;
// 	OLDIM = NEWIM;
// 	NEWRE = OLDRE * OLDRE - OLDIM * OLDIM + PR;
// 	NEWIM = 2 * OLDRE * OLDIM + PI;
// 	if ((NEWRE * NEWRE + NEWIM * NEWIM) > 4)
// 		break ;
// }
