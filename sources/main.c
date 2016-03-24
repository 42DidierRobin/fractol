/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 13:13:42 by rdidier           #+#    #+#             */
/*   Updated: 2016/03/24 18:22:23 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		main(int argc, char **argv)
{
	int		ret;

	ret = 0;
	if (argc == 2)
		ret = launch_it(argv[1]);
	if (!ret)
		ft_putstr("Erreur Args. Veuillez preciser lune des trois fract");
		ft_putstr("als suivantes :\njulia ou mandelbrot ou burningship\n");
	return (0);
}
