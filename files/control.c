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
// #include <conio.h>
#include <math.h>

int				key_control(int key, t_window *info)
{
	if (key == 53)
		exit(1);
	if (info->type_fract != JULIA)
	{
		if (key == 123) {
			info->fractol->indent_x -= 0.2 / info->fractol->zoom_z;
			// info->fractol->indent_x -= (10 / info->fractol->zoom_z);
		}
		else if (key == 124) {
			info->fractol->indent_x += 0.2 / info->fractol->zoom_z;
			// info->fractol->indent_x += (10 / info->fractol->zoom_z);
		}
		else if (key == 125) {
			info->fractol->indent_y += 0.2 / info->fractol->zoom_z;
			// info->fractol->indent_y -= (10 / info->fractol->zoom_z);
		}
		else if (key == 126) {
			info->fractol->indent_y -= 0.2 / info->fractol->zoom_z;
			// info->fractol->indent_y += (10 / info->fractol->zoom_z);
		}
		else if (key == 69) {
			info->fractol->zoom_z *= 1.1;
		}
		else if (key == 78) {
			info->fractol->zoom_z *= .9;
		}
	}
	else if (key == 89)
		info->fractol->indent_r += 10;
	else if (key == 91)
		info->fractol->indent_r -= 10;

	else if (key == 86)
		info->fractol->indent_g += 10;
	else if (key == 87)
		info->fractol->indent_g -= 10;

	else if (key == 7 && info->fractol->depth < 1000)
		info->fractol->depth *= 2;
	else if (key == 6 && info->fractol->depth > 4)
		info->fractol->depth /= 2;

	display_fractols(info);
	return (0);
}

int				mouse_control(int x, int y, t_window *info)
{
	if (info->type_fract == JULIA && x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		info->fractol->cre = (float)(x - (WIDTH / 2)) / (WIDTH / 2);
		info->fractol->cim = (float)(y - (HEIGHT / 2)) / HEIGHT;
		display_fractols(info);
	}
	return (0);
}

int				mouse_zoom(int button, int x, int y, t_window *info)
{

	if ((button == 4 || button == 5 || button == 1) && x >= 0 && y >= 0 && x <= WIDTH && y <= HEIGHT)
	{
		if (button == 1) {
			info->fractol->indent_x -= 0.0002 * (WIDTH / 2 - x) / info->fractol->zoom_z;
			info->fractol->indent_y -= 0.0002 * (HEIGHT / 2 - y) / info->fractol->zoom_z;
		}
		else if (button == 4)
		{
			info->fractol->zoom_z *= 1.1;
			info->fractol->indent_x -= 0.0002 * (WIDTH / 2 - x) / info->fractol->zoom_z;
			info->fractol->indent_y -= 0.0002 * (HEIGHT / 2 - y) / info->fractol->zoom_z;
		}
		else
			info->fractol->zoom_z *= 0.9;
		display_fractols(info);
	}
	return (0);
}


