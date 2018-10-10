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


// void		display_mandelbrot(t_window *info)
// {
// 	t_fract 	*fractol;
// 	float		old_pr;
// 	float		old_pi;


// 	intmax_t 	total;

//  	fractol = info->fractol;
// 	total = 0;
// 	fractol->y = 0;
// 	while (fractol->y++ < HEIGHT - 1)
// 	{
//  		fractol->x = 0;
// 		while (fractol->x++ < WIDTH - 1)
// 		{

// 			fractol->ci = 1.5 * ((float)fractol->x - WIDTH / 2) / (0.5 * fractol->zoom_z * WIDTH) + fractol->indent_x;
// 			fractol->cr = ((float)fractol->y - HEIGHT / 2) / (0.5 * fractol->zoom_z * HEIGHT) + fractol->indent_y;

// 			fractol->pi = 0.0;
// 			fractol->pr = 0.0;

// 			fractol->k = 0;
// 			while (fractol->k++ < DEPTH)
// 			{
// 				old_pr = fractol->pr;
// 				old_pi = fractol->pi;
// 				fractol->pr = old_pr * old_pr - old_pi * old_pi + fractol->pr;
// 				fractol->pi = 2 * old_pr * old_pi + fractol->pi;
// 				if ((fractol->pr * fractol->pr + fractol->pi * fractol->pi) > fractol->depth)
// 					break ;
// 			}
// 		put_color_on_map(info);
// 		}
// 	}
// }

void		display_mandelbrot(t_window *info)
{
	t_fract 	*fractol;
	float		tmp;


	intmax_t 	total;

 	fractol = info->fractol;
	total = 0;
	fractol->y = 0;
	while (fractol->y++ < HEIGHT - 1)
	{
 		fractol->x = 0;
		while (fractol->x++ < WIDTH - 1)
		{
			fractol->ci = ((float)fractol->x - WIDTH / 2) / (0.33 * fractol->zoom_z * WIDTH) + fractol->indent_x;
			fractol->cr = ((float)fractol->y - HEIGHT / 2) / (0.3 * fractol->zoom_z * HEIGHT) + fractol->indent_y;
			// fractol->ci = ((float)fractol->x  - WIDTH / 2) / 160.0 + fractol->indent_x;
			// fractol->cr = ((float)fractol->y - HEIGHT / 2) / 140.0 + fractol->indent_y;
			
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
				total++;
			}
			put_color_on_map(info);
		}
	}
	printf("TOTAL : (%ld)\n", total);
}
