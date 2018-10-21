/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 18:26:31 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/12 18:26:32 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

void			put_color_on_map(t_window *info)
{
	t_fract		*fractol;
	int			r_new;
	int			g_new;
	int			b_new;

	fractol = info->fractol;
	if (fractol->k < DEPTH)
	{
		fractol = info->fractol;
		r_new = ((fractol->k % 255) * fractol->k) + fractol->indent_r;
		g_new = ((fractol->k % 255) * fractol->k) + fractol->indent_g;
		b_new = ((fractol->k % 255) * fractol->k) + fractol->indent_b;
		info->data[fractol->x + fractol->y * WIDTH] = fractol->black_color ? 0 \
			: b_new | (g_new << 8) | (r_new << 16);
	}
	else
		info->data[fractol->x + fractol->y * WIDTH] = 0;
}

void			print_user_interface(t_window *info)
{
	char	*str;

	mlx_string_put(info->mlx, info->win, 41, 35, 0xffffff, "Controls Keys");
	mlx_string_put(info->mlx, info->win, 37, 65, 0xffffff, "Move = ^ v < >");
	mlx_string_put(info->mlx, info->win, 37, 80, 0xffffff, "Depth = { and }");
	str = ft_itoa(info->fractol->depth);
	mlx_string_put(info->mlx, info->win, 200, 80, 0xffffff, str);
	free(str);
	mlx_string_put(info->mlx, info->win, 37, 95, 0xffffff, "Zoom = - and +");
	mlx_string_put(info->mlx, info->win, 37, 110, 0xffffff, "R = Q and W");
	str = ft_itoa(info->fractol->indent_r);
	mlx_string_put(info->mlx, info->win, 200, 110, 0xffffff, str);
	free(str);
	mlx_string_put(info->mlx, info->win, 37, 125, 0xffffff, "G = A and S");
	str = ft_itoa(info->fractol->indent_g);
	mlx_string_put(info->mlx, info->win, 200, 125, 0xffffff, str);
	free(str);
	mlx_string_put(info->mlx, info->win, 37, 140, 0xffffff, "B = Z and X");
	str = ft_itoa(info->fractol->indent_b);
	mlx_string_put(info->mlx, info->win, 200, 140, 0xffffff, str);
	free(str);
	mlx_string_put(info->mlx, info->win, 37, 248, 0xb5b5b5, "Controls Mouse");
	mlx_string_put(info->mlx, info->win, 37, 276, 0xffffff, "Zoom = SCROLL");
	if (info->type_fract == JULIA)
		mlx_string_put(info->mlx, info->win, 37, 155, 0xffffff, "Block = B");
}
