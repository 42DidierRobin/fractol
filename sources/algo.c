/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 14:14:01 by rdidier           #+#    #+#             */
/*   Updated: 2016/03/24 16:47:12 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		give_color(t_color *clr, int iter, int iter_max)
{
	if (iter == iter_max)
	{	
		clr->r = 0;
		clr->g = 0;
		clr->b = 0;
	}
	else
	{
		clr->r = (iter * 7) % 255;
		clr->g = (142 + (iter * 2)) % 255;
		clr->b = (255 - (iter * 8)) % 255;
	}
}

void		do_it(t_frctld *data)
{
	int			i;
	int			j;
	t_cmplx		*c;
	t_cmplx		*z;
	t_color		*clr;
	
	clr = new_color(0,0,0);
	z = new_cmplx(0,0);
	c = new_cmplx(0,0);
	i = -1;
	while (++i < WINDOW_W)
	{
		j = -1;
		while (++j < WINDOW_H)
		{
			give_color(clr, data->fct(data, i, j, data->julia, z), data->imax);
			pix_on_img(data->img, i, j, clr);
		}
	}
}

int			mandelbrot(t_frctld *data, int x, int y, t_cmplx *c, t_cmplx *z)
{
	int			i;
	double		tmp;

	tmp = 0;
	c->r = x / (WINDOW_W / (data->xmax - data->xmin)) + data->xmin;
	c->i = y / (WINDOW_H / (data->ymax - data->ymin)) + data->ymin;
	z->r = 0;
	z->i = 0;
	i = -1;
	while (++i < data->imax)
	{
		tmp = z->r;
		z->r = z->r * z->r - z->i * z->i + c->r;
		z->i = 2 * tmp * z->i + c->i;
		if ((z->r * z->r + z->i * z->i) > 4.0)
			break;
	}
	return (i);
}

int			julia(t_frctld *data, int x, int y, t_cmplx *c, t_cmplx *z)
{
	int			i;
	double		tmp;

	tmp = 0;
	z->r = x / (WINDOW_W / (data->xmax - data->xmin)) + data->xmin;
	z->i = y / (WINDOW_H / (data->ymax - data->ymin)) + data->ymin;
	i = -1;
	while (++i < data->imax)
	{
		tmp = z->r;
		z->r = z->r * z->r - z->i * z->i + c->r;
		z->i = 2 * tmp * z->i + c->i;
		if ((z->r * z->r + z->i * z->i) > 4.0)
			break;
	}
	return (i);
}

int			burningship(t_frctld *data, int x, int y, t_cmplx *c, t_cmplx *z)
{
	int			i;
	double		tmp;

	tmp = 0;
	c->r = x / (WINDOW_W / (data->xmax - data->xmin)) + data->xmin;
	c->i = y / (WINDOW_H / (data->ymax - data->ymin)) + data->ymin;
	z->r = 0;
	z->i = 0;
	i = -1;
	while (++i < data->imax)
	{
		if (z->r < 0)
			z->r = -z->r;
		if (z->i < 0)
			z->i = -z->i;
		tmp = z->r;
		z->r = z->r * z->r - z->i * z->i + c->r;
		z->i = 2 * tmp * z->i + c->i;
		if ((z->r * z->r + z->i * z->i) > 4.0)
			break;
	}
	return (i);
}
