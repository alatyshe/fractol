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

int				ft_key_control(int key, t_window *info)
{
	if (key == 53)
		exit(1);
	else if (key == 123)
		info->fractol->indent_x -= (10 / info->fractol->zoom_z);
	else if (key == 124)
		info->fractol->indent_x += (10 / info->fractol->zoom_z);
	else if (key == 125)
		info->fractol->indent_y -= (10 / info->fractol->zoom_z);
	else if (key == 126)
		info->fractol->indent_y += (10 / info->fractol->zoom_z);
	else if (key == 69)
		info->fractol->zoom_z *= .9;
	else if (key == 78)
		info->fractol->zoom_z *= 1.1;

	else if (key == 89)
		info->fractol->indent_r += 10;
	else if (key == 91)
		info->fractol->indent_r -= 10;

	else if (key == 86)
		info->fractol->indent_g += 10;
	else if (key == 87)
		info->fractol->indent_g -= 10;

	else if (key == 7 && info->fractol->depth < 10000)
		info->fractol->depth *= 2;
	else if (key == 6 && info->fractol->depth > 4)
		info->fractol->depth /= 2;

	display_fractols(info);

	return (0);
}