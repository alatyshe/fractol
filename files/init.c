/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 18:26:31 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/12 18:26:32 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

t_fract 		*init_new_fract()
{
	t_fract		*fractol;

	fractol = (t_fract *)malloc(sizeof(t_fract));


	fractol->pi = 0;
	fractol->pr = 0;
	fractol->ci = 0;
	fractol->cr = 0;
	fractol->tmp = 0;

	// julia
 	fractol->cre = -0.7;
	fractol->cim = 0.27015;

	// 
	fractol->indent_x = 0;
 	fractol->indent_y = 0;
 	fractol->zoom_z = 1;
 	fractol->m = 0;

 	// colors options
 	fractol->black_color = 0;
 	fractol->r = 0;
	fractol->g = 0;
	fractol->b = 0;
	fractol->indent_r = 100;
	fractol->indent_g = 100;
	fractol->indent_b = 50;

	fractol->depth = 16;
	fractol->x = 0;
	fractol->y = 0;
	fractol->k = 0;
	return (fractol);
}

t_window		*init_new_win(int name_fractol)
{
	t_window		*info;
	char			*name;

	if (!(info = (t_window *)malloc(sizeof(t_window))))
		return (0);


	if (name_fractol == MANDELBROT)
		name = "Mandelbrot";
	else if (name_fractol == JULIA)
		name = "Julia";
	else if (name_fractol == NEWTON)
		name = "Newton";

	info->width = WIDTH;
	info->height = HEIGHT;
	info->size_line = 0;
	info->endian = 0;
	info->bits_per_pixel = 0;
	info->type_fract = name_fractol;
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, WIDTH, HEIGHT, name);
	info->img = NULL;
	info->data = NULL;


	// give memmory for fract struct
	info->fractol = init_new_fract();
	return (info);
}
