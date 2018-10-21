/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 18:26:31 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/12 18:26:32 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void			key_control_1(int key, t_window *info)
{
	if (key == 123)
		info->fractol->indent_x -= 0.2 / info->fractol->zoom_z;
	else if (key == 124)
		info->fractol->indent_x += 0.2 / info->fractol->zoom_z;
	else if (key == 125)
		info->fractol->indent_y += 0.2 / info->fractol->zoom_z;
	else if (key == 126)
		info->fractol->indent_y -= 0.2 / info->fractol->zoom_z;
	else if (key == 69)
		info->fractol->zoom_z *= 1.05;
	else if (key == 78)
		info->fractol->zoom_z *= .95;
}

int				key_control(int key, t_window *info)
{
	if (key == 53)
		exit(1);
	key_control_1(key, info);
	if (key == 12)
		info->fractol->indent_r = (info->fractol->indent_r - 4) & 255;
	else if (key == 13)
		info->fractol->indent_r = (info->fractol->indent_r + 4) & 255;
	else if (key == 0)
		info->fractol->indent_g = (info->fractol->indent_g - 4) & 255;
	else if (key == 1)
		info->fractol->indent_g = (info->fractol->indent_g + 4) & 255;
	else if (key == 6)
		info->fractol->indent_b = (info->fractol->indent_b - 4) & 255;
	else if (key == 7)
		info->fractol->indent_b = (info->fractol->indent_b + 4) & 255;
	else if (key == 30 && info->fractol->depth < 10000)
		info->fractol->depth += 10;
	else if (key == 33 && info->fractol->depth > 4)
		info->fractol->depth -= 10;
	else if (key == 11)
		info->fractol->block = 1;
	display_fractols(info);
	return (0);
}

int				mouse_control(int x, int y, t_window *info)
{
	if (info->type_fract == JULIA
		&& x >= 0 && x < WIDTH
		&& y >= 0 && y < HEIGHT
		&& info->fractol->block != 1)
	{
		info->fractol->cre = (float)(x - (WIDTH / 2)) / (WIDTH / 2);
		info->fractol->cim = (float)(y - (HEIGHT / 2)) / HEIGHT;
		display_fractols(info);
	}
	return (0);
}

int				mouse_zoom(int button, int x, int y, t_window *info)
{
	if ((button == 4 || button == 5)
		&& x >= 0 && y >= 0 && x <= WIDTH && y <= HEIGHT)
	{
		if (button == 4)
		{
			info->fractol->zoom_z *= 1.1;
			info->fractol->indent_x -= 0.003 * \
				(WIDTH / 2 - x) / info->fractol->zoom_z;
			info->fractol->indent_y -= 0.003 * \
				(HEIGHT / 2 - y) / info->fractol->zoom_z;
		}
		else
			info->fractol->zoom_z *= 0.95;
		display_fractols(info);
	}
	return (0);
}
