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
# define HEIGHT		400
# define DEPTH		5000	// чем выше этотпоказатель, тем "глубже" получается картинка

# include "../miniLibX/mlx.h"
# include "../libft/header/libft.h"
# include "../libft/header/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct	s_color
{
	int				r;
	int				g;
	int				b;
	int				a;
}				t_color;

typedef struct	s_window
{
	int				width;
	int				height;
	double			indent_x;
	double			indent_y;
	void			*mlx;
	void			*win;
}				t_window;


t_window		*lst_new_win();
void			display_mandelbrot(t_window *w);

#endif
