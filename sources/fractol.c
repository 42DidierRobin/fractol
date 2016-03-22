/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 13:14:52 by rdidier           #+#    #+#             */
/*   Updated: 2016/03/22 13:38:30 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			launch_it(void)
{
	t_frctld	*data;

	data = (t_frctld*)malloc(sizeof(t_frctld));
	if (!(data->ptr = mlx_init()))
		return (0);
	data->win = mlx_new_window(data->ptr, WINDOW_W, WINDOW_H, "Fract'ol by Mathiisss");
	if (!mlx_key_hook(data->ptr, listener, (void*)data))
		/*
			{
				mlx_destroy_window(data->ptr, data->win);
				//mlx_destroy_image(mlx->ptr, mlx->img->self);
				exit(0);
			}*/
	mlx_loop(data->ptr);
	return (1);
}

int			listener(int keycode, void *d)
{
	t_frctld	*data;

	data = (t_frctld*)d;
	printf("key pressed : %d\n", keycode);
	if (keycode == 52)
		return (0);
	return (1);
}
