/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 18:26:31 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/12 18:26:32 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"


// NEWRE = 1.5 * (X - WIDTH / 2) / (0.5 * ZOOM * WIDTH) + X_MOVE_J;
// NEWIM = (Y - HEIGHT / 2) / (0.5 * ZOOM * HEIGHT) + Y_MOVE_J;
// I = -1;
// while (++I < DEPTH)
// {
// 	OLDRE = NEWRE;
// 	OLDIM = NEWIM;
// 	NEWRE = OLDRE * OLDRE - OLDIM * OLDIM + CRE;
// 	NEWIM = 2 * OLDRE * OLDIM + CIM;
// 	if ((NEWRE * NEWRE + NEWIM * NEWIM) > 4)
// 		break ;
// }


    // //calculate the initial real and imaginary part of z, based on the pixel location and zoom and position values
    // newRe = 1.5 * (fractol->x - WIDTH / 2) / (0.5 * fractol->zoom_z * WIDTH) + fractol->indent_x;
    // newIm = (fractol->y - HEIGHT / 2) / (0.5 * fractol->zoom_z * HEIGHT) + fractol->indent_y;
    // //i will represent the number of iterations
    // int i;
    // //start the iteration process
    // for(i = 0; i < maxIterations; i++)
    // {
    //   //remember value of previous iteration
    //   oldRe = newRe;
    //   oldIm = newIm;
    //   //the actual iteration, the real and imaginary part are calculated
    //   newRe = oldRe * oldRe - oldIm * oldIm + cRe;
    //   newIm = 2 * oldRe * oldIm + cIm;
    //   //if the point is outside the circle with radius 2: stop
    //   if((newRe * newRe + newIm * newIm) > 4) break;



void		display_julia(t_window *info)
{
	t_fract 	*fractol;
	float		tmp;
	float 		new_re;
	float		new_im;
	float		old_re;
	float		old_im;

 	float cre = -0.7;
	float cim = 0.27015;

	new_re = 0;
	new_im = 0;
	old_re = 0;
	old_im = 0;

 	fractol = info->fractol;
 	fractol->x = 0;
	while (fractol->x++ < WIDTH - 1)
	{
		fractol->y = 0;
		while (fractol->y++ < HEIGHT - 1)
		{
 			new_re = 1.5 * (fractol->x - WIDTH / 2) / (0.5 * fractol->zoom_z * WIDTH) + fractol->indent_x;
    		new_im = (fractol->y - HEIGHT / 2) / (0.5 * fractol->zoom_z * HEIGHT) + fractol->indent_y;

			fractol->k = 0;

			while (fractol->k++ < DEPTH)
			{
				old_re = new_re;
				old_im = new_im;
				new_re = old_re * old_re - old_im * old_im + cim;
				new_im = 2 * old_re * old_im + cre;
				if ((new_re * new_re + new_im * new_im) > 4)
					break ;
			}
			put_color_on_map(info);
		}
	}	
}