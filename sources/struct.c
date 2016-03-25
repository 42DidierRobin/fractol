/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 14:38:40 by rdidier           #+#    #+#             */
/*   Updated: 2016/03/25 14:56:42 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_color			*new_color(int r, int g, int b)
{
	t_color	*c;

	c = (t_color*)malloc(sizeof(t_color));
	c->r = r;
	c->g = g;
	c->b = b;
	return (c);
}

t_cmplx			*new_cmplx(double r, double i)
{
	t_cmplx		*ret;

	ret = (t_cmplx*)malloc(sizeof(t_cmplx));
	ret->r = r;
	ret->i = i;
	return (ret);
}
