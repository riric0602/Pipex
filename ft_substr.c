/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:06:47 by rchbouki          #+#    #+#             */
/*   Updated: 2023/06/26 19:40:06 by rchbouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(char *s, int test)
{
	int		i;
	char	*dup;

	dup = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dup)
		return (NULL);
	i = -1;
	while (s[++i])
		dup[i] = s[i];
	dup[i] = '\0';
	if (test == 1)
		free(s);
	return (dup);
}

static char	*ft_temp(char *new, char *s, int start, int len)
{
	int	i;

	i = 0;
	while ((i < len) && (s[start + i]))
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_substr_split(char *s, int start, int len)
{
	char	*new;

	if (!s)
		return (NULL);
	if ((start >= ft_strlen(s)) || !ft_strlen(s) || !len)
	{
		new = malloc(sizeof(char) * 1);
		if (!new)
			return (NULL);
		new[0] = '\0';
		return (new);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	new = ft_temp(new, s, start, len);
	return (new);
}

char	*ft_substr(char *s)
{
	char	*new;
	int		i;
	int		start;

	i = 0;
	start = 0;
	while (s[start] != '\n')
		start++;
	start += 1;
	if (!s[start + i])
		return (free(s), NULL);
	new = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	if (!new)
		return (NULL);
	while ((s[start + i]))
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	free(s);
	return (new);
}
