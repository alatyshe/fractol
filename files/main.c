/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 18:26:31 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/12 18:26:32 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

int			check_name_fractol(char *str)
{
	t_window	*win;

	win = lst_new_win();
	if (!ft_strcmp(str, "mandelbrot"))
		display_mandelbrot(win);
	else if (!ft_strcmp(str,"julia"))
		;// display_julia(win);
	else
		return (0);
	return (1);
}

int			main(int argc, char **argv)
{
	char	*str;

	if (argc != 2)
		ft_printf("usage: ./fractol [map.fdf]\n");
	else if (check_name_fractol(argv[1]))
		;
	else
		ft_printf("WTF BITH\n");
	return (0);
}
