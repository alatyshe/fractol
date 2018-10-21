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

#include "../../header/fractol.h"

void		calculate_julia(t_fract *f)
{
	double		old_re;
	double		old_im;

	while (f->k++ < f->depth)
	{
		old_re = f->ci;
		old_im = f->cr;
		f->ci = old_re * old_re - old_im * old_im + f->cim;
		f->cr = 2 * old_re * old_im + f->cre;
		if ((f->ci * f->ci + f->cr * f->cr) > f->depth)
			break ;
	}
}

void		display_julia(t_window *info)
{
	t_fract		*f;

	f = info->fractol;
	f->y = 0;
	f->ci = 0;
	f->cr = 0;
	while (f->y++ < HEIGHT - 1)
	{
		f->x = 0;
		while (f->x++ < WIDTH - 1)
		{
			f->ci = 1.5 * (f->x - WIDTH / 2) / \
				(0.5 * f->zoom_z * WIDTH) + f->indent_x;
			f->cr = (f->y - HEIGHT / 2) / \
				(0.5 * f->zoom_z * HEIGHT) + f->indent_y;
			f->k = 0;
			calculate_julia(f);
			put_color_on_map(info);
		}
	}
}
