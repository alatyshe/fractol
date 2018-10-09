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

void		display_mandelbrot(t_window *info)
{
	t_fract 	*fractol;
	float		tmp;

 	fractol = info->fractol;

	fractol->y = 0;
	while (fractol->y++ < HEIGHT - 1)
	{
 		fractol->x = 0;
		while (fractol->x++ < WIDTH - 1)
		{
			// NEWRE = 1.5 * (X - WIDTH / 2) / (0.5 * ZOOM * WIDTH) + X_MOVE_J;
			// NEWIM = (Y - HEIGHT / 2) / (0.5 * ZOOM * HEIGHT) + Y_MOVE_J;

			fractol->ci = ((float)fractol->x  - WIDTH / 2) / 160.0 + fractol->indent_x;
			fractol->cr = ((float)fractol->y - HEIGHT / 2) / 140.0 + fractol->indent_y;
			
			fractol->pi = 0.0;
			fractol->pr = 0.0;

			fractol->k = 0;

			while (fractol->k++ < DEPTH)
			{
				tmp = fractol->pr * fractol->pr - fractol->pi * fractol->pi;
				fractol->pi = (2 * fractol->pr * fractol->pi + fractol->ci) / fractol->zoom_z;
				fractol->pr = (tmp + fractol->cr) / fractol->zoom_z;
				if ((fractol->pr * fractol->pr + fractol->pi * fractol->pi) > fractol->depth)
					break;
			}
			put_color_on_map(info);
		}
	}	
}