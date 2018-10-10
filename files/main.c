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

int			exit_fractol()
{
	exit(1);
	return (1);
}

void		print_usage()
{
	ft_printf("usage: ./fractol [name]\n");
	ft_printf("    name:\n");
	ft_printf("\tmandelbrot\n");
	ft_printf("\tjulia\n");
	ft_printf("\tnewton\n");
}

int			parse_names(char *str)
{
	if (!ft_strcmp(str, "mandelbrot"))
		return (MANDELBROT);
	else if (!ft_strcmp(str, "julia"))
		return (JULIA);
	else if (!ft_strcmp(str, "newton"))
		return (NEWTON);
	else
	{
		print_usage();
		exit(1);
	}
}

void		display_fractols(t_window *info)
{
	info->img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	info->data = (int *)mlx_get_data_addr(info->img, &info->bits_per_pixel, &info->size_line, &info->endian);
	
	if (info->type_fract == MANDELBROT)
		display_mandelbrot(info);
	else if (info->type_fract == JULIA)
		display_julia(info);
	else if (info->type_fract == NEWTON)
		display_newton(info);

	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
	mlx_destroy_image(info->mlx, info->img);
}

int			check_name_fractol(char *str)
{
	int			name_fractol;
	t_window	*info;

	name_fractol = parse_names(str);
	info = init_new_win(name_fractol);
	
	display_fractols(info);
	mlx_hook(info->win, 2, 0, key_control, info);
	mlx_hook(info->win, 6, 0, mouse_control, info);
	mlx_mouse_hook(info->win, mouse_zoom, info);
	mlx_hook(info->win, 17, 0, exit_fractol, info);
	mlx_loop(info->mlx);

	return (1);
}

int			main(int argc, char **argv)
{
	char	*str;

	if (argc != 2)
		print_usage();
	else if (check_name_fractol(argv[1]))
		;
	return (0);
}
