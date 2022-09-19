/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 20:14:31 by bprovoos      #+#    #+#                 */
/*   Updated: 2022/09/19 14:25:43 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# define WIDTH 1000
# define HEIGHT 1000

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft.h"
# include "MLX42.h"

/*
	cx = -0.7;
	cy = 0.27015;
*/
typedef struct s_fractol_vars
{
	int		i_x;
	int		i_y;
	int		mouse_x;
	int		mouse_y;
	int		max;
	double	zoom;
	double	move_x;
	double	move_y;
	double	cx;
	double	cy;
}	t_fractol_vars;

/*
Jump table names and functions
*/
typedef struct s_fractol_table
{
	char	*names;
	char	*usage;
	int		(*function)(t_fractol_vars vars);
}	t_fractol_table;

typedef struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_fractol_table	*fractol;
	char			*name;
	t_fractol_vars	vars;
}	t_data;

mlx_t		*init_screen(char *name);
mlx_image_t	*create_img(mlx_t *mlx);
int			mandlebrot_pixel(t_fractol_vars vars);
int			julia_pixel(t_fractol_vars vars);
void		loop_screen_actions(t_data *data);
void		draw_fractol(t_data *data);
double		ft_atof(const char *str);
int			str_is_double(char *str);

#endif
