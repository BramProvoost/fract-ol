/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 20:18:22 by bprovoos      #+#    #+#                 */
/*   Updated: 2022/09/15 20:20:34 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	hook(void *param)
{
	t_data	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
	{
		data->vars.move_y -= 0.05 / data->vars.zoom;
		draw_fractol(data);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
	{
		data->vars.move_y += 0.05 / data->vars.zoom;
		draw_fractol(data);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
	{
		data->vars.move_x -= 0.05 / data->vars.zoom;
		draw_fractol(data);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
	{	
		data->vars.move_x += 0.05 / data->vars.zoom;
		draw_fractol(data);
	}
}

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_data	*data;

	data = param;
	if (ydelta > 0)
		data->vars.zoom += data->vars.zoom * 0.1;
	else if (ydelta < 0)
		data->vars.zoom -= data->vars.zoom * 0.1;
	xdelta = 0;
	draw_fractol(data);
}

void	loop_screen_actions(t_data *data)
{
	mlx_loop_hook(data->mlx, &hook, data);
	mlx_scroll_hook(data->mlx, &my_scrollhook, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
}
