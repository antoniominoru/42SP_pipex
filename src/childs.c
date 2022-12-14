/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:28:40 by aminoru-          #+#    #+#             */
/*   Updated: 2022/07/21 23:12:02 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_cmd(char *cmd, char **paths)
{
	char	*tmp;
	char	*command;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

void	infile_child(t_pipex pipex, char **argv, char **envp)
{
	dup2(pipex.fd[1], 1);
	close(pipex.fd[0]);
	dup2(pipex.infile, 0);
	pipex.cmd_args = ft_split(argv[2], ' ');
	pipex.comand = get_cmd(pipex.cmd_args[0], pipex.cmds);
	if (!pipex.comand)
	{
		child_free(&pipex);
		perror_error("first command not found");
	}
	execve(pipex.comand, pipex.cmd_args, envp);
}

void	outfile_child(t_pipex pipex, char **argv, char **envp)
{
	dup2(pipex.fd[0], 0);
	close(pipex.fd[1]);
	dup2(pipex.outfile, 1);
	pipex.cmd_args = ft_split(argv[3], ' ');
	pipex.comand = get_cmd(pipex.cmd_args[0], pipex.cmds);
	if (!pipex.comand)
	{
		child_free(&pipex);
		perror_error("second command not found");
	}
	execve(pipex.comand, pipex.cmd_args, envp);
}
