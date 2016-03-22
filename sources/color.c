/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:54:41 by rdidier           #+#    #+#             */
/*   Updated: 2016/03/22 15:59:33 by rdidier          ###   ########.fr       */
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
