/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 18:26:31 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/12 18:26:32 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

void			put_color_on_map(t_window *info)
{
	t_fract 	*fractol;

	int 		r_new;
	int			g_new;
	int 		b_new;

	fractol = info->fractol;
	if (fractol->k < DEPTH)
	{
		fractol = info->fractol;
		r_new = ((fractol->k % 255) * fractol->k) + fractol->indent_r;
		g_new = ((fractol->k % 255) * fractol->k) + fractol->indent_g;
		b_new = ((fractol->k % 255) * fractol->k) + fractol->indent_b;
		info->data[fractol->x + fractol->y * WIDTH] = fractol->black_color ? 0 : b_new | (g_new << 8) | (r_new << 16);
	}
	else
		info->data[fractol->x + fractol->y * WIDTH] = 0;
}