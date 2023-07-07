/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:34:33 by rchbouki          #+#    #+#             */
/*   Updated: 2023/06/26 19:36:41 by rchbouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int				i;
	unsigned char	cmp_1;
	unsigned char	cmp_2;

	i = 0;
	if (!n)
		return (n);
	if ((!s1 || !s2) && (!*s1 || !*s2))
		return (0);
	cmp_1 = *s1;
	cmp_2 = *s2;
	while (i < n && (cmp_1 || cmp_2))
	{
		cmp_1 = (unsigned char)s1[i];
		cmp_2 = (unsigned char)s2[i];
		if (cmp_1 != cmp_2)
			return (cmp_1 - cmp_2);
		i++;
	}
	return (cmp_1 - cmp_2);
}

static int	ft_fullstr(const char *str)
{
	int	len;

	len = ft_strlen((char *)str);
	write(1, str, len);
	return (len);
}

static int	ft_options(char c, va_list param)
{
	int	res;

	res = 0;
	if (c == 'c' || c == '%')
		res = ft_write_c(c, param);
	else if (c == 's')
		res = ft_write_s(param);
	else if (c == 'd' || c == 'i')
		res = ft_write_d(param, "0123456789", 0);
	return (res);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		cp;
	va_list	param;

	i = 0;
	cp = 0;
	if (!ft_strchr(str, '%'))
		return (ft_fullstr(str));
	va_start(param, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			cp += ft_options(str[i + 1], param);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			cp++;
		}
		i++;
	}
	va_end(param);
	return (cp);
}
