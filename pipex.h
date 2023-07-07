/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:09:26 by rchbouki         #+#    #+#             */
/*   Updated: 2023/02/21 13:09:27 by rchbouki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/errno.h>
# include <sys/wait.h>
# include <stdarg.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define ENOENT 2
# define EACCES 13

typedef struct s_files
{
	int	input;
	int	output;
	int	argc;
}	t_files;

int		ft_isprint(int c);
int		ft_write_s(va_list param);
int		ft_printf(const char *str, ...);
int		ft_write_c(char c, va_list	param);
int		ft_write_d(va_list param, char *base, int test);

char	*get_next_line(int fd);

int		create_process(int n, int *pfd, int pid);
void	ft_here_doc(char **argv, t_files *file, int *argc);
char	*ft_command(char *path, int len_cmd);

void	ft_putchar(char c);
void	ft_putstr(char *s);
int		ft_strlen(char *s);
char	*ft_substr(char *s);
char	**ft_split(char *s, char c);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(char *s, int test);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
int		ft_strncmp(char *s1, char *s2, int n);
char	*ft_substr_split(char *s, int start, int len);

#endif