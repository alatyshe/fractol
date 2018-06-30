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
	t_window	*info;

	info = lst_new_win();
	
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, WIDTH, HEIGHT, "mlx 42");

	if (!ft_strcmp(str, "mandelbrot"))
		display_mandelbrot(info);
	else if (!ft_strcmp(str,"julia"))
		;// display_julia(info);
	else
		return (0);


	// keys parsing
	mlx_hook(info->win, 2, 0, ft_key_control, info);
	// mlx_hook(info->win, 6, 0, mouse_move_funct, info);
	// mlx_hook(info->win, 17, 0, exit_fractol, info);
	mlx_loop(info->mlx);

	return (1);
}

int			main(int argc, char **argv)
{
	char	*str;

	if (argc != 2)
	{
		ft_printf("usage: ./fractol [map.fdf]\n");
		ft_printf("\tmandelbrot\n");
		ft_printf("\tjulia\n");
	}
	else if (check_name_fractol(argv[1]))
		;
	return (0);
}
