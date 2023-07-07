/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:07:28 by rchbouki          #+#    #+#             */
/*   Updated: 2023/06/23 18:44:40 by rchbouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_isprint(int c)
{
	if ((c == 26) || (c < 32) || (c > 126))
		return (0);
	return (1);
}

char	*ft_strchr(const char *s, int c)
{
	char	l;
	char	*sub_set;

	sub_set = (char *)(s);
	l = (char)(c);
	while (*sub_set)
	{
		if (*sub_set == l)
			return (sub_set);
		sub_set++;
	}
	if (l == '\0')
		return (sub_set);
	return (NULL);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	cmp_1;
	unsigned char	cmp_2;

	i = 0;
	if ((!s1 || !s2) && (!*s1 || !*s2))
		return (0);
	cmp_1 = *s1;
	cmp_2 = *s2;
	while ((s1[i] || s2[i]) && (cmp_1 || cmp_2))
	{
		cmp_1 = (unsigned char)s1[i];
		cmp_2 = (unsigned char)s2[i];
		if (cmp_1 != cmp_2)
			return (cmp_1 - cmp_2);
		i++;
	}
	return (cmp_1 - cmp_2);
}
