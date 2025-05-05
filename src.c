/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kato <kato@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:02:42 by kato              #+#    #+#             */
/*   Updated: 2025/05/05 18:45:32 by kato             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_cmd1(char *infile, int *pipefd, char **args, char **envp)
{
	int	fd;

	fd = open(infile, O_RDONLY);
	if (fd < 0)
		perror_exit(infile);
	dup2(fd, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(fd);
	close(pipefd[0]);
	close(pipefd[1]);
	execve("/bin/sh", args, envp);
	ft_putstr_fd("pipex: ", 2);
	perror(args[2]);
	exit(127);
}

void	execute_cmd2(char *outfile, int *pipefd, char **args, char **envp)
{
	int	fd;

	fd = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		perror_exit(outfile);
	dup2(pipefd[0], STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	close(pipefd[0]);
	close(pipefd[1]);
	execve("/bin/sh", args, envp);
	ft_putstr_fd("pipex: ", 2);
	perror(args[2]);
	exit(127);
}
