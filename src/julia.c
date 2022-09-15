/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/08 14:48:14 by bprovoos      #+#    #+#                 */
/*   Updated: 2022/09/15 13:41:14 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	julia_pixel(t_fractol_vars vars)
{
	int		i;
	double	zx;
	double	zy;
	double	xtemp;

	zx = 2 * ((double)vars.i_x - WIDTH / 2) / (0.5 * WIDTH * vars.zoom) \
				+ vars.move_x;
	zy = 2 * ((double)vars.i_y - HEIGHT / 2) / (0.5 * HEIGHT * vars.zoom) \
				+ vars.move_y;
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
