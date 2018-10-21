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
#include <math.h>

void		calculate_mandelbrot(t_fract *f)
{
	while (f->k++ < f->depth)
	{
		f->tmp = f->pr * f->pr - f->pi * f->pi;
		f->pi = (2 * f->pr * f->pi + f->ci) / f->zoom_z;
		f->pr = (f->tmp + f->cr) / f->zoom_z;
		if ((f->pr * f->pr + f->pi * f->pi) > f->depth)
			break ;
	}
}

void		display_mandelbrot(t_window *info)
{
	t_fract		*f;

	f = info->fractol;
	f->y = 0;
	while (f->y++ < HEIGHT - 1)
	{
		f->x = 0;
		while (f->x++ < WIDTH - 1)
		{
			f->ci = ((float)f->x - WIDTH / 2) / \
				(0.3 * f->zoom_z * WIDTH) + f->indent_x;
			f->cr = ((float)f->y - HEIGHT / 2) / \
				(0.3 * f->zoom_z * HEIGHT) + f->indent_y;
			f->pi = 0.0;
			f->pr = 0.0;
			f->k = 0;
			calculate_mandelbrot(f);
			put_color_on_map(info);
		}
	}
}
