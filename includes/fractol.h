/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 13:26:01 by rdidier           #+#    #+#             */
/*   Updated: 2016/03/24 18:44:16 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRACTOL_H
# define __FRACTOL_H

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
	t_cmplx			*julia;
	int				(*fct)(struct s_frctld *data, int x, int y,
						t_cmplx *c, t_cmplx *z);
	double			xmin;
	double			xmax;
	double			ymin;
	double			ymax;
	int				imax;
	void			*ptr;
	void			*win;
	char			mouse_stop;
    t_img           *img;
}					t_frctld;

//Listener
int					listener(int keycode, void *data);

//mouse
int					mouse_click(int k, int x, int y, void *data);
int					mouse_moove(int x, int y, void *data);

//color
t_color				*new_color(int r, int g, int b);

//algo
void				do_it(t_frctld *data);
int					mandelbrot(t_frctld *data, int i, int j,
								t_cmplx *c, t_cmplx *z);
int					julia(t_frctld *data, int i, int j,
								t_cmplx *c, t_cmplx *z);
int					burningship(t_frctld *data, int i, int j,
								t_cmplx *c, t_cmplx *z);

//Fractol
int					launch_it(char *name);


//complex
t_cmplx				*new_cmplx(double r, double i);

//IMAGE
int                 pix_on_img(t_img *img, int x, int y, t_color *clr);

#endif
