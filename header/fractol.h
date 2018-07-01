/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 16:49:51 by alatyshe          #+#    #+#             */
/*   Updated: 2017/11/25 17:06:39 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define CYAN		"\x1b[36m"
# define BLACK		"\x1b[37m"
# define RESET		"\x1b[0m"
# define BOLD_ON	"\x1b[1m"
# define BOLD_OFF	"\x1b[22m"

# define WIDTH		800
# define HEIGHT		800
# define DEPTH		500// чем выше этот показатель, тем "глубже" получается картинка

# include "../miniLibX/mlx.h"
# include "../libft/header/libft.h"
# include "../libft/header/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct	s_fract
{
	float			pi;
	float			pr;
	float			ci;
	float			cr;
	float			tmp;

	// 
	float			indent_x;
 	float			indent_y;
 	float			zoom_z;
 	float			m;

 	int 			black_color;
 	int				r;
	int				g;
	int				b;
	int				indent_r;
	int				indent_g;
	int				indent_b;
 	
	int 			k;
	int				x;
	int				y;
	int 			depth;
}				t_fract;

typedef struct	s_window
{
	int				width;
	int				height;
	int 			size_line;
	int 			endian;
	int 			bits_per_pixel;


	int 			*data;
	void			*mlx;
	void			*win;
	void			*img;

	int 			type_fract;
	t_fract			*fractol;
}				t_window;


void			display_fractols(t_window *info);


t_window		*lst_new_win();
void			display_mandelbrot(t_window *w);
void			display_julia(t_window *w);

// key_contol.c
int				ft_key_control(int key, t_window *win);

// colors.c
void			put_color_on_map(t_window *info);

#endif
