/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_listener.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 17:46:33 by rdidier           #+#    #+#             */
/*   Updated: 2016/03/24 18:44:13 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		mouse_moove(int x, int y, void *data)
{
	t_frctld	*d;

	d = (t_frctld*)data;
	if (x < 0 || x > WINDOW_W || y < 0 || y > WINDOW_H || d->mouse_stop)
		return (0);
	d->julia->r = -0.7 + (double)x / 1000;
	d->julia->i = 0.27015 + (double)y / 1000;	
	do_it(d);
	mlx_clear_window(d->ptr, d->win);
	mlx_put_image_to_window(d->ptr, d->win, d->img->self, 0, 0);
	return (0);
}

int			mouse_click(int k, int x, int y, void *data)
{
	t_frctld	*d;

	d = (t_frctld*)data;
	if (x < 0 || y < 0 || x > WINDOW_W || y > WINDOW_H)
		return (0);
	d = (t_frctld*)data;
	if (k == 5)
		listener(24, data);
	else if (k == 7)
		listener(27, data);
	else if (k == 1)
		d->mouse_stop = (d->mouse_stop == 0 ) ? 1 : 0;
	do_it(d);
	mlx_clear_window(d->ptr, d->win);
	mlx_put_image_to_window(d->ptr, d->win, d->img->self, 0, 0);
	return (1);
}
