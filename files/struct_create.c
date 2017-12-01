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
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, WIDTH, HEIGHT, "mlx 42");
	win->indent_x = WIDTH / 2;
	win->indent_y = HEIGHT / 2;
	return (win);
}