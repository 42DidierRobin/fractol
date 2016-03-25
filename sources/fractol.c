/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 13:14:52 by rdidier           #+#    #+#             */
/*   Updated: 2016/03/25 14:56:54 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void			data_init_julia(t_frctld *d)
{
	d->xmin = -2;
	d->xmax = 2;
	d->ymax = 1.5;
	d->ymin = -1.5;
	d->fct = julia;
	d->mouse_stop = 0;
	d->julia = new_cmplx(-0.7, 0.27015);
}

static t_frctld		*data_init(char *name)
{
	t_frctld	*d;

	d = (t_frctld*)malloc(sizeof(t_frctld));
	d->ptr = mlx_init();
	d->win = mlx_new_window(d->ptr, WINDOW_W, WINDOW_H,
									"Fract'ol by Mathiisss");
	d->xmin = -1.5;
	d->xmax = 0.6;
	d->ymin = -1.2;
	d->ymax = 1.2;
	d->imax = 42;
	d->julia = new_cmplx(0, 0);
	if (ft_strequ(name, "julia"))
		data_init_julia(d);
	else if (ft_strequ(name, "mandelbrot"))
		d->fct = mandelbrot;
	else if (ft_strequ(name, "burningship"))
		d->fct = burningship;
	else
		return (NULL);
	d->img = (t_img*)malloc(sizeof(t_img));
	d->img->self = mlx_new_image(d->ptr, WINDOW_W, WINDOW_H);
	d->img->buff = mlx_get_data_addr(d->img->self, &d->img->bpp,
										&d->img->bpl, &d->img->endian);
	return (d);
}

int					launch_it(char *name)
{
	t_frctld	*data;

	data = data_init(name);
	if (!data)
		return (0);
	do_it(data);
	mlx_put_image_to_window(data->ptr, data->win, data->img->self, 0, 0);
	mlx_key_hook(data->win, listener, (void*)data);
	mlx_hook(data->win, 6, (1L << 6), mouse_moove, (void*)data);
	mlx_mouse_hook(data->win, mouse_click, (void*)data);
	mlx_loop(data->ptr);
	return (1);
}
