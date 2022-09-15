/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atof.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 15:51:53 by bprovoos      #+#    #+#                 */
/*   Updated: 2022/09/15 18:32:01 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	get_precision(const char *str)
{
	int	precicion;

	precicion = 0;
	while (ft_isdigit(*str))
		str++;
	if (*str != '.')
		return (precicion);
	str++;
	while (ft_isdigit(*str))
	{
		str++;
		precicion++;
	}
	return (precicion);
}

double	set_dot_and_sign(double nbr, int precision, int neg)
{
	while (precision > 0)
	{
		nbr /= 10;
		precision--;
	}
	if (neg)
		return (nbr * -1);
	return (nbr);
}

int	basic_atoi(char *str)
{
	int	nbr;

	nbr = 0;
	while (ft_isdigit(*str))
	{
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	return (nbr);
}

double	ft_atof(const char *str)
{
	double	nbr;
	char	neg;
	int		precision;

	neg = (*str == '-');
	if (*str == '-' || *str == '+')
		str++;
	nbr = 0.0;
	while (ft_isdigit(*str))
	{
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	precision = get_precision(str);
	if (*str == '.')
	{
		str++;
		while (ft_isdigit(*str))
		{
			nbr = nbr * 10 + (*str - '0');
			str++;
		}
	}
	nbr = set_dot_and_sign(nbr, precision, neg);
	return (nbr);
}
