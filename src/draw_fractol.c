/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_fractol.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/08 15:41:35 by bprovoos      #+#    #+#                 */
/*   Updated: 2022/09/19 10:23:42 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	*get_fractol_function(t_fractol_table *fractol, char *name)
{
	int	index;

	index = 0;
	while (fractol[index].names)
	{
		if (ft_strncmp(fractol[index].names, name, 11) == 0)
			return (fractol[index].function);
		index++;
	}
	ft_putstr_fd("fractol not found", 1);
	exit(1);
}

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	get_color(int iteration, int max_iterations)
{
	if (iteration == max_iterations)
		iteration = 0;
	return (get_rgba(iteration * 4, iteration * 6, iteration * 2, 255));
}

void	draw_fractol(t_data *data)
{
	int			(*function)(t_fractol_vars vars);
	int			iteration;
	int			color;

	mlx_delete_image(data->mlx, data->img);
	data->img = create_img(data->mlx);
	function = get_fractol_function(data->fractol, data->name);
	data->vars.i_y = 0;
	while (data->vars.i_y < data->mlx->height)
	{
		data->vars.i_x = 0;
		while (data->vars.i_x < data->mlx->height)
		{
			iteration = function(data->vars);
			color = get_color(iteration, data->vars.max);
			mlx_put_pixel(data->img, data->vars.i_x, data->vars.i_y, color);
			data->vars.i_x++;
		}
		data->vars.i_y++;
	}
}
