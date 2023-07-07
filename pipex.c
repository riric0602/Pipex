/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:35:42 by richbouki         #+#    #+#             */
/*   Updated: 2023/02/20 21:34:51 by richbouki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_child(int *pfd, int n, t_files file)
{
	close(pfd[0]);
	if (file.input != STDIN_FILENO)
	{
		dup2(file.input, STDIN_FILENO);
		close(file.input);
	}
	if (n == 1 && (file.output != STDOUT_FILENO))
	{
		dup2(file.output, STDOUT_FILENO);
		close(file.output);
	}
	else
	{
		dup2(pfd[1], STDOUT_FILENO);
		close(pfd[1]);
	}
	if (n == file.argc && file.input == -1)
		exit(0);
}

static void	ft_exec_cmd(char *argv, char **path)
{
	int		i;
	char	*cmd;
	char	**cmd_options;

	i = -1;
	if (!path)
	{
		cmd_options = ft_split(argv, ' ');
		if (access(cmd_options[0], X_OK) == 0)
			if (execve(NULL, cmd_options, NULL) == -1)
				exit(EXIT_FAILURE);
	}
	else
	{
		while (path[++i])
		{
			cmd = ft_command(path[i], ft_strlen(argv));
			cmd_options = ft_split(argv, ' ');
			cmd = ft_strjoin(cmd, cmd_options[0]);
			if (access(cmd, X_OK) == 0)
				if (execve(cmd, cmd_options, NULL) == -1)
					exit(EXIT_FAILURE);
		}
	}
}

static void	ft_pipeline(int n, char **argv, t_files file, char **path)
{
	int		pfd[2];
	int		pid;
	int		status;

	pid = create_process(n, pfd, 0);
	if (pid == 0)
	{
		ft_child(pfd, n, file);
		ft_exec_cmd(*argv, path);
	}
	else
	{
		close(pfd[1]);
		close(file.input);
		if (n == 1)
			while (file.argc--)
				waitpid(-1, &status, 0);
		if (file.input == -1)
			file.input = dup(pfd[0]);
		else
			dup2(pfd[0], file.input);
		close(pfd[0]);
		if (n != 0)
			ft_pipeline(n - 1, argv + 1, file, path);
	}
}

static void	ft_open_errors(char *filename)
{
	if (errno == ENOENT)
		ft_printf("File '%s' does not exist.\n", filename);
	else if (errno == EACCES)
		ft_printf("Permission denied for file '%s'.\n", filename);
	else
		ft_printf("Error opening file '%s'. Error code: %d.\n", filename, errno);
}

int	main(int argc, char *argv[], char **envp)
{
	t_files	file;
	char	**path;

	path = NULL;
	if (argc < 5)
	{
		ft_printf("Error : must have more than 5 arguments.\n");
		exit(EXIT_FAILURE);
	}
	file.output = open(argv[argc - 1], O_CREAT | O_TRUNC | O_WRONLY, 0777);
	if (ft_strcmp(argv[1], "here_doc") == 0)
		ft_here_doc(argv++, &file, &argc);
	else
	{
		file.input = open(argv[1], O_RDONLY);
		if (file.input < 0)
			ft_open_errors(argv[1]);
	}
	while (*envp && ft_strncmp(*envp, "PATH=", 5) != 0)
		envp++;
	if (*envp)
		path = ft_split(*envp + 5, ':');
	file.argc = argc - 3;
	ft_pipeline(argc - 3, argv + 2, file, path);
	return (0);
}
