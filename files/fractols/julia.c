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


void		display_julia(t_window *info)
{
	t_fract 	*fractol;
	float		tmp;
	float 		new_re;
	float		new_im;
	float		old_re;
	float		old_im;

	new_re = 0;
	new_im = 0;
	old_re = 0;
	old_im = 0;

 	fractol = info->fractol;
 	fractol->y = 0;
	while (fractol->y++ < HEIGHT - 1)
	{
		fractol->x = 0;
		while (fractol->x++ < WIDTH - 1)
		{

 			new_re = 1.5 * (fractol->x - WIDTH / 2) / (0.5 * fractol->zoom_z * WIDTH) + fractol->indent_x;
    		new_im = (fractol->y - HEIGHT / 2) / (0.5 * fractol->zoom_z * HEIGHT) + fractol->indent_y;

			fractol->k = 0;

			while (fractol->k++ < DEPTH)
			{
				old_re = new_re;
				old_im = new_im;
				new_re = old_re * old_re - old_im * old_im + fractol->cim;
				new_im = 2 * old_re * old_im + fractol->cre;
				if ((new_re * new_re + new_im * new_im) > 4)
					break ;
			}

			put_color_on_map(info);
		}
	}
}