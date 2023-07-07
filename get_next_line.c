/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:19:35 by rchbouki          #+#    #+#             */
/*   Updated: 2023/06/23 15:41:14 by rchbouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_get_last(char *temp)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (temp[i] != '\n' && temp[i])
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (temp[i] != '\n' && temp[i])
		str[j++] = temp[i++];
	if (temp[i] == '\n')
		str[j] = '\n';
	str[j + 1] = '\0';
	return (str);
}

char	*ft_read_buff(int fd)
{
	char	*temp;
	int		res;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	res = read(fd, temp, BUFFER_SIZE);
	temp[res] = '\0';
	if (res <= 0)
		return (free(temp), NULL);
	return (temp);
}

char	*ft_read_line(int fd, char *stat)
{
	char	*temp;
	char	*final;
	char	*last;

	temp = ft_read_buff(fd);
	if (!temp && !stat)
		return (free(temp), temp = NULL);
	if (!stat)
		final = ft_strdup("", 0);
	else
		final = ft_strdup(stat, 0);
	while (temp && !ft_strchr(temp, '\n'))
	{
		last = ft_strdup(final, 1);
		final = ft_strjoin(last, temp);
		free(temp);
		temp = ft_read_buff(fd);
	}
	if (temp)
	{
		last = ft_strdup(final, 1);
		final = ft_strjoin(last, temp);
	}
	return (free(temp), final);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*temp;
	char		*result;

	if (read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (free(str), str = NULL);
	if (str && ft_strchr(str, '\n'))
	{
		temp = ft_get_last(str);
		result = ft_strdup(str, 1);
		str = ft_substr(result);
		return (temp);
	}
	temp = ft_read_line(fd, str);
	if (!temp)
		return (free(str), str = NULL);
	if (ft_strchr(temp, '\n'))
	{
		result = ft_get_last(temp);
		free(str);
		str = ft_substr(temp);
		return (result);
	}
	return (free(str), str = NULL, temp);
}
