/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 13:26:01 by rdidier           #+#    #+#             */
/*   Updated: 2016/03/22 18:05:46 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRACTOL_H
# define __FRACTOL_H

//TEMP
#include <stdio.h>
//TEMP

# include <stdlib.h>
# include <math.h>
# include "../libft/libft.h"
# include <mlx.h>

# define WINDOW_H 		800
# define WINDOW_W	 	800

typedef unsigned char uchar;

typedef struct		s_cmplx
{
	double			r;
	double			i;
}					t_cmplx;

typedef struct		s_color
{
	uchar			r;
	uchar			g;
	uchar			b;
}					t_color;

typedef struct      s_img
{
    void            *self;
    char            *buff;
    int             bpp;
    int             bpl;
	int				endian;
}                   t_img;

typedef struct		s_frctld
{
	double			xmin;
	double			xmax;
	double			ymin;
	double			ymax;
	int				imax;
	void			*ptr;
	void			*win;
    t_img           *img;
}					t_frctld;

//color
t_color				*new_color(int r, int g, int b);

//algo
void				do_it(t_frctld *data);
int					mandelbrot(t_frctld *data, int i, int j,
								t_cmplx *c, t_cmplx *z);

//Fractol
int					launch_it(void);
int					listener(int keycode, void *d);

//complex
		void				print_cmplx(t_cmplx *a);
t_cmplx				*new_cmplx(double r, double i);
t_cmplx				*mult_cmplx(t_cmplx *a, t_cmplx *b);
t_cmplx				*add_cmplx(t_cmplx *a, t_cmplx *b);
double				dist_cmplx(t_cmplx *a);

//IMAGE
int                 pix_on_img(t_img *img, int x, int y, t_color *clr);

#endif
