/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:39:50 by rchbouki          #+#    #+#             */
/*   Updated: 2023/03/30 14:45:31 by rchbouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_putnbr_base_0(int nb, char *base, int *len)
{
	int	i;
	int	res;

	i = 0;
	if (nb == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	while (base[i])
		i++;
	if (nb >= i)
	{
		ft_putnbr_base_0(nb / i, base, len);
		ft_putnbr_base_0(nb % i, base, len);
	}
	else
	{
		ft_putchar(base[nb]);
		*len += 1;
	}
	res = *len;
	return (res);
}

static int	ft_putnbr_base_1(unsigned int nb, char *base, int *len)
{
	unsigned int	i;
	int				res;

	i = 0;
	while (base[i])
		i++;
	if (nb >= i)
	{
		ft_putnbr_base_1(nb / i, base, len);
		ft_putnbr_base_1(nb % i, base, len);
	}
	else
	{
		ft_putchar(base[nb]);
		*len += 1;
	}
	res = *len;
	return (res);
}

int	ft_write_d(va_list param, char *base, int test)
{
	int				nb_0;
	unsigned int	nb_1;
	int				len;
	int				*p;

	p = &len;
	len = 0;
	if (test == 0)
	{
		nb_0 = (va_arg(param, int));
		if ((nb_0 < 0) && (nb_0 != -2147483648))
		{
			ft_putchar('-');
			len++;
			nb_0 *= -1;
		}
		return (ft_putnbr_base_0(nb_0, base, p));
	}
	else
	{
		nb_1 = (va_arg(param, unsigned int));
		return (ft_putnbr_base_1(nb_1, base, p));
	}
}

int	ft_write_c(char c, va_list param)
{
	if (c == 'c')
	{
		c = (va_arg(param, int));
		ft_putchar(c);
	}
	else
		ft_putchar(c);
	return (1);
}

int	ft_write_s(va_list param)
{
	char	*s;
	int		len;

	s = (char *)(va_arg(param, char *));
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}
