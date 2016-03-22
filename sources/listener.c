/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listener.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 17:41:31 by rdidier           #+#    #+#             */
/*   Updated: 2016/03/22 18:05:38 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	listener2(int keycode, t_frctld *d)
{
	double		zoom[2];

	zoom[0] = (d->xmax - d->xmin) / 8;
	zoom[1] = (d->ymax - d->ymin) / 8;
	if (keycode == 2)
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
	else if (keycode == 24)
	{
		d->xmin+= zoom[0];
		d->xmax-= zoom[0];
		d->ymax-= zoom[1];
		d->ymin+= zoom[1];
		d->imax += 10;
	}
	else if (keycode == 27)
	{
		d->xmin-= zoom[0];
		d->xmax+= zoom[0];
		d->ymax+= zoom[1];
		d->ymin-= zoom[1];
		d->imax -= 10;
	}
}

int			listener(int keycode, void *data)
{
	t_frctld	*d;

	d = (t_frctld*)data;
	//TEMP
		printf("key pressed : %d\n", keycode);
	//TEMP

	if (keycode == 53)
	{
		mlx_destroy_window(d->ptr, d->win);
		mlx_destroy_image(d->ptr, d->img->self);
		exit(0);
	}
	else if (keycode == 0)
	{
		d->xmin-= (d->xmax - d->xmin) / 8;
		d->xmax-= (d->xmax - d->xmin) / 8;
	}
	listener2(keycode, d);
	do_it(d);
	mlx_clear_window(d->ptr, d->win);
	mlx_put_image_to_window(d->ptr, d->win, d->img->self, 0, 0);
	return (1);
}
