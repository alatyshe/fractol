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

void		parse_names(char *str, t_window *info)
{
	if (!ft_strcmp(str, "mandelbrot"))
		info->type_fract = 1;
	else if (!ft_strcmp(str,"julia"))
		info->type_fract = 2;
	else
		exit(1);	
}

void		display_fractols(t_window *info)
{
	info->img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	info->data = (int *)mlx_get_data_addr(info->img, &info->bits_per_pixel, &info->size_line, &info->endian);
	if (info->type_fract == 1)
		display_mandelbrot(info);
	else if (info->type_fract == 2)
		display_julia(info);

	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
	mlx_destroy_image(info->mlx, info->img);
}

int			check_name_fractol(char *str)
{
	t_window	*info;

	info = lst_new_win();

	parse_names(str, info);	

	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, WIDTH, HEIGHT, "mlx 42");

	display_fractols(info);
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
