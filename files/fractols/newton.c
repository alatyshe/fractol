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

void		calculate_newton(t_fract *f)
{
	double		old_re;
	double		old_im;

	f->tmp = 1.0;
	while (f->tmp > 0.000001 && f->k++ < f->depth)
	{
		old_re = f->ci;
		old_im = f->cr;
		f->tmp = (f->ci * f->ci + f->cr * f->cr) * \
		(f->ci * f->ci + f->cr * f->cr);
		f->ci = (2 * f->ci * f->tmp + f->ci * f->ci - f->cr * f->cr) / \
		(3.0 * f->tmp);
		f->cr = (2 * f->cr * (f->tmp - old_re)) / (3.0 * f->tmp);
		f->tmp = (f->ci - old_re) * (f->ci - old_re) + (f->cr - old_im) * \
		(f->cr - old_im);
	}
}

void		display_newton(t_window *info)
{
	t_fract		*f;

	f = info->fractol;
	f->y = 0;
	while (f->y++ < HEIGHT - 1)
	{
		f->x = 0;
		while (f->x++ < WIDTH - 1)
		{
			f->ci = (f->x - (WIDTH / 2)) / \
				(f->zoom_z * WIDTH) + f->indent_x;
			f->cr = (f->y - (HEIGHT / 2)) / \
				(f->zoom_z * HEIGHT) + f->indent_y;
			f->k = 0;
			calculate_newton(f);
			put_color_on_map(info);
		}
	}
}
