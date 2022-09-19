/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   str_is_double.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/19 14:22:16 by bprovoos      #+#    #+#                 */
/*   Updated: 2022/09/19 14:25:23 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	str_is_double(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(ft_isdigit(str[i]) || str[i] == '.' || str[i] == '-'))
			return (0);
		i++;
	}
	return (1);
}
