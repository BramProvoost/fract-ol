/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 14:04:08 by bprovoos      #+#    #+#                 */
/*   Updated: 2022/09/19 14:29:04 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	show_usage(t_fractol_table *fractol)
{
	int	index;

	ft_putstr_fd(\
		"error: arguments are not correct\n"\
		"useage options: \n"\
		, 1);
	index = 0;
	while (fractol[index].names)
	{
		ft_putstr_fd("./fractol ", 1);
		ft_putstr_fd(fractol[index].names, 1);
		ft_putstr_fd(fractol[index].usage, 1);
		ft_putstr_fd("\n", 1);
		index++;
	}
	return (1);
}

int	is_unvalid_input(int argc, char **argv, t_data *data)
{
	int	i;

	if (argc < 2 || !argv)
		return (show_usage(data->fractol));
	// if (argc == 4)
	// {
	// 	if (!str_is_double(argv[2]) || !str_is_double(argv[3]))
	// 		return (show_usage(data->fractol));
	// }
	i = 0;
	while (data->fractol[i].names)
	{
		if (ft_strncmp(data->fractol[i].names, argv[1], 100) == 0)
			return (0);
		i++;
	}
	return (show_usage(data->fractol));
}

void	init_fractols(t_data *data)
{
	static t_fractol_table	fractol[] = {
	{"mandelbrot", "", mandlebrot_pixel},
	{"julia", " [f] [f]", julia_pixel},
	};

	data->fractol = fractol;
	data->vars.move_x = 0;
	data->vars.move_y = 0;
	data->vars.max = 50;
	data->vars.zoom = 1;
	data->vars.cx = 0;
	data->vars.cy = 0;
}

void	handle_input(int argc, char **argv, t_data *data)
{
	data->name = argv[1];
	if (argc == 4)
	{
		data->vars.cx = ft_atof(argv[2]);
		data->vars.cy = ft_atof(argv[3]);
	}
	else
	{
		data->vars.cx = 0;
		data->vars.cy = 0;
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		exit (EXIT_SUCCESS);
	init_fractols(data);
	if (is_unvalid_input(argc, argv, data))
		exit (EXIT_FAILURE);
	handle_input(argc, argv, data);
	data->mlx = init_screen(data->name);
	draw_fractol(data);
	loop_screen_actions(data);
	exit (EXIT_SUCCESS);
}
