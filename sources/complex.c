/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 12:39:48 by rdidier           #+#    #+#             */
/*   Updated: 2016/03/22 15:10:26 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TEMP
#include <stdio.h>
//TEMP

#include "../includes/fractol.h"

//TEMP
void			print_cmplx(t_cmplx *a)
{
	if (a->i >= 0)
		printf("Nbre cmplx : %f + %fi\n", a->r, a->i);
	else	
		printf("Nbre cmplx : %f - %fi\n", a->r, - a->i);
}
//TEMP

t_cmplx			*new_cmplx(double r, double i)
{
	t_cmplx		*ret;

	ret = (t_cmplx*)malloc(sizeof(t_cmplx));
	ret->r = r;
	ret->i = i;
	return (ret);
}

t_cmplx			*mult_cmplx(t_cmplx *a, t_cmplx *b)
{
	return (new_cmplx(a->r * b->r - a->i * b->i,
                      a->r * b->i + a->i * b->r)); 
}

double			dist_cmplx(t_cmplx *a)
{
	return (a->r * a->r + a->i * a->i);
}

t_cmplx			*add_cmplx(t_cmplx *a, t_cmplx *b)
{
	return (new_cmplx(a->r + b->r, a->i + b->i));
}
