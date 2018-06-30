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

t_window		*lst_new_win()
{
	t_window		*win;

	if (!(win = (t_window *)malloc(sizeof(t_window))))
		return (0);

	win->width = WIDTH;
	win->height = HEIGHT;
	win->indent_x = WIDTH / 2;
	win->indent_y = HEIGHT / 2;

	// give memmory for fract struct
	win->fractol = (t_fract *)malloc(sizeof(t_fract));

	win->fractol->indent_x = 0;
	win->fractol->indent_y = 0;
	win->fractol->zoom_z = 1;
	// win->fractol->x = -400;
	return (win);
}