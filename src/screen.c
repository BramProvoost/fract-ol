/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   screen.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/08 12:55:44 by bprovoos      #+#    #+#                 */
/*   Updated: 2022/09/15 20:19:25 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

mlx_t	*init_screen(char *name)
{
	mlx_t	*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, name, false);
	if (!mlx)
		exit(EXIT_FAILURE);
	return (mlx);
}

mlx_image_t	*create_img(mlx_t *mlx)
{
	mlx_image_t	*img;

	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		exit(EXIT_FAILURE);
	return (img);
}
