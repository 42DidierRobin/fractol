/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 13:14:52 by rdidier           #+#    #+#             */
/*   Updated: 2016/03/22 18:05:39 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static t_frctld		*data_init()
{
	t_frctld	*d;

	d = (t_frctld*)malloc(sizeof(t_frctld));
	d->ptr = mlx_init();
	d->win = mlx_new_window(d->ptr, WINDOW_W, WINDOW_H,
									"Fract'ol by Mathiisss");
	d->xmin = -1.5;
	d->xmax =  0.6;
	d->ymin = -1.2;
	d->ymax = 1.2;
	d->imax = 42;
	d->img = (t_img*)malloc(sizeof(t_img));
	d->img->self = mlx_new_image(d->ptr, WINDOW_W, WINDOW_H);
	d->img->buff = mlx_get_data_addr(d->img->self, &d->img->bpp, 
										&d->img->bpl, &d->img->endian);
	return (d);
}

int			launch_it(void)
{
	t_frctld	*data;

	data = data_init();
	do_it(data);
	mlx_put_image_to_window(data->ptr, data->win, data->img->self, 0, 0);
	mlx_key_hook(data->win, listener, (void*)data);
	mlx_loop(data->ptr);
	return (1);
}
