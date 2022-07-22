/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:56:30 by aminoru-          #+#    #+#             */
/*   Updated: 2022/07/22 21:14:32 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	files_open(t_pipex *pipex, int argc, char **argv)
{
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile == -1)
		perror_error("No open file at the first argument");
	pipex->outfile = open(argv[argc - 1], O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (pipex->outfile == -1)
		perror_error("No open file at the last argument");
}

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		perror_error("Incorrect numbers of arguments!");
	files_open(&pipex, argc, argv);
	if (pipe(pipex.fd) == -1)
		perror_error("pipex error");
	pipex.cmd_path = find_path(envp);
	pipex.cmds = ft_split(pipex.cmd_path, ':');
	pipex.pid1 = fork();
	if (pipex.pid1 < 0)
		perror_error("Fork error");
	if (pipex.pid1 == 0)
		infile_child(pipex, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 < 0)
		perror_error("Fork error");
	if (pipex.pid2 == 0)
		outfile_child(pipex, argv, envp);
	close_pipe(&pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	parent_free(&pipex);
	return (0);
}
