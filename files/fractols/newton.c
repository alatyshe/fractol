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

void				display_newton(t_window *info)
{
	t_fract 	*fractol;
	float		tmp;
	float 		new_re;
	float		new_im;
	float		old_re;
	float		old_im;

 	fractol = info->fractol;
 	fractol->y = 0;
	while (fractol->y++ < HEIGHT - 1)
	{
		fractol->x = 0;
		while (fractol->x++ < WIDTH - 1)
		{
			new_re = (fractol->x - (WIDTH / 2)) / (fractol->zoom_z * WIDTH) + fractol->indent_x;
			new_im = (fractol->y - (HEIGHT / 2)) / (fractol->zoom_z * HEIGHT) + fractol->indent_y;
			fractol->k = 0;
			tmp = 1.0;
			while (tmp > 0.000001 && fractol->k++ < DEPTH)
			{
				old_re = new_re;
				old_im = new_im;
				tmp = (new_re * new_re + new_im * new_im) * \
				(new_re * new_re + new_im * new_im);
				new_re = (2 * new_re * tmp + new_re * new_re - new_im * new_im) / \
				(3.0 * tmp);
				new_im = (2 * new_im * (tmp - old_re)) / (3.0 * tmp);
				tmp = (new_re - old_re) * (new_re - old_re) + (new_im - old_im) * \
				(new_im - old_im);
			}
			put_color_on_map(info);
		}
	}
}