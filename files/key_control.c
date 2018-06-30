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
	{
		printf("123 key left\n");
		info->fractol->indent_x += 10;
	}
	else if (key == 124)
	{
		printf("124 key right\n");
		info->fractol->indent_x -= 10;
	}

	else if (key == 125)
	{
		printf("125 key down\n");
		info->fractol->indent_y -= 10;
	}
	else if (key == 126)
	{
		printf("126 key up\n");
		info->fractol->indent_y += 10;
	}
	else if (key == 24)
	{
		printf("24 plus\n");
		info->fractol->zoom_z *= .9;
	}
	else if (key == 27)
	{
		printf("27 minus\n");
		info->fractol->zoom_z *= 1.1;
	}

	mlx_clear_window(info->mlx, info->win);
	display_mandelbrot(info);
	return (0);
}