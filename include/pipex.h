/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:56:27 by aminoru-          #+#    #+#             */
/*   Updated: 2022/07/21 23:12:24 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdlib.h>
// lib of 42 projects
# include "../lib/libft/libft.h"
# include "../lib/libft/get_next_line.h"
# include "../lib/printf/ft_printf.h"

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];
	int		infile;
	int		outfile;
	char	*cmd_path;
	char	**cmds;
	char	**cmd_args;
	char	*comand;
}		t_pipex;

int		main(int argc, char **argv, char **envp);
char	*get_cmd(char *cmd, char **paths);
void	infile_child(t_pipex pipex, char **argv, char **envp);
void	outfile_child(t_pipex pipex, char **argv, char **envp);
void	perror_error(char *msg);
void	close_pipe(t_pipex *pipex);
void	child_free(t_pipex *pipex);
void	parent_free(t_pipex	*pipex);
void	files_open(t_pipex *pipex, int argc, char **argv);
char	*find_path(char **envp);
#endif