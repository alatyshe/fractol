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

void		display_mandelbrot(t_window *info)
{
	t_fract 	*fractol;
	float		tmp;

 	fractol = info->fractol;
 	fractol->x = 0;
	while (fractol->x++ < WIDTH - 1)
	{
		fractol->y = 0;
		while (fractol->y++ < HEIGHT - 1)
		{
			fractol->ci = ((float)fractol->x + fractol->indent_x - WIDTH / 2) / 160.0;
			fractol->cr = ((float)fractol->y + fractol->indent_y - HEIGHT / 2) / 140.0;
			
			fractol->pi = 0.0;
			fractol->pr = 0.0;

			fractol->k = 0;

			while (fractol->k++ < DEPTH)
			{
				tmp = fractol->pr * fractol->pr - fractol->pi * fractol->pi;
				fractol->pi = (2 * fractol->pr * fractol->pi + fractol->ci) * fractol->zoom_z;
				fractol->pr = (tmp + fractol->cr) * fractol->zoom_z;
				if ((fractol->pr * fractol->pr + fractol->pi * fractol->pi) > fractol->depth)
					break;
			}
			put_color_on_map(info);
		}
	}	
}