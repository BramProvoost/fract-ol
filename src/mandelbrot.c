/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/08 09:50:51 by bprovoos      #+#    #+#                 */
/*   Updated: 2022/09/15 20:15:26 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	mandlebrot_pixel(t_fractol_vars vars)
{
	int				i;
	double			zx;
	double			zy;
	double			xtemp;
	const double	x_ofset = -0.5;

	zx = 2 * ((double)vars.i_x - WIDTH / 2) / (0.5 * WIDTH * vars.zoom) \
				+ vars.move_x + x_ofset;
	zy = 2 * ((double)vars.i_y - HEIGHT / 2) / (0.5 * HEIGHT * vars.zoom) \
				+ vars.move_y;
	vars.cx = zx;
	vars.cy = zy;
	i = 0;
	while (zx * zx + zy * zy < 4 && i < vars.max)
	{
		xtemp = zx * zx - zy * zy;
		zy = 2 * zx * zy + vars.cy;
		zx = xtemp + vars.cx;
		i++;
	}
	return (i);
}
