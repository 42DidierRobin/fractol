/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listener.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 17:41:31 by rdidier           #+#    #+#             */
/*   Updated: 2016/03/24 18:24:43 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	listener4(int keycode, t_frctld *d)
{
	int	step;

	step = 10;
	if (d->imax > 100)
		step = 5;
	else if (d->imax > 142)
		step = 3;
	else if (d->imax > 200)
		step = 1;
	if (keycode == 126)
		d->imax+= step;
	else if (keycode == 125)
		d->imax-= step;
	if (d->imax < 20)
		d->imax = 20;
}

static void	listener3(int keycode, t_frctld *d)
{
	double		zoom[2];
		
	zoom[0] = (d->xmax - d->xmin) / 8;
	zoom[1] = (d->ymax - d->ymin) / 8;
	if (keycode == 24)
	{
		d->xmin+= zoom[0];
		d->xmax-= zoom[0];
		d->ymax-= zoom[1];
		d->ymin+= zoom[1];
	}
	else if (keycode == 27)
	{
		d->xmin-= zoom[0];
		d->xmax+= zoom[0];
		d->ymax+= zoom[1];
		d->ymin-= zoom[1];
	}
}

static void	listener2(int keycode, t_frctld *d)
{
	double		zoom[2];

	zoom[0] = (d->xmax - d->xmin) / 8;
	zoom[1] = (d->ymax - d->ymin) / 8;
	if (keycode == 0)
	{
		d->xmin-= zoom[0];
		d->xmax-= zoom[0];
	}
	else if (keycode == 2)
	{
		d->xmin+= zoom[0];
		d->xmax+= zoom[0];
	}
	else if (keycode == 13)
	{
		d->ymin-= zoom[1];
		d->ymax-= zoom[1];
	}
	else if (keycode == 1)
	{
		d->ymin+= zoom[1];
		d->ymax+= zoom[1];
	}
}

int			listener(int keycode, void *data)
{
	t_frctld	*d;

	d = (t_frctld*)data;
	if (keycode == 53)
	{
		mlx_destroy_window(d->ptr, d->win);
		mlx_destroy_image(d->ptr, d->img->self);
		exit(0);
	}
	listener2(keycode, d);
	listener3(keycode, d);
	listener4(keycode, d);	
	mlx_clear_window(d->ptr, d->win);
	do_it(d);
	mlx_put_image_to_window(d->ptr, d->win, d->img->self, 0, 0);
	return (1);
}
