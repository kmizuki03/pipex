/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kato <kato@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:02:42 by kato              #+#    #+#             */
/*   Updated: 2025/05/05 18:58:56 by kato             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_cmd1(char *infile, int *pipefd, char **args, char **envp)
{
	int	fd;

	fd = open(infile, O_RDONLY);
	if (fd < 0)
		perror_exit(infile);
	if (dup2(fd, STDIN_FILENO) < 0)
		perror_exit("dup2");
	if (dup2(pipefd[1], STDOUT_FILENO) < 0)
		perror_exit("dup2");
	close(fd);
	close(pipefd[0]);
	close(pipefd[1]);
	if (!args || !args[0])
	{
		ft_putstr_fd("pipex: invalid command\n", 2);
		exit(127);
	}
	execve(args[0], args, envp);
	ft_putstr_fd("pipex: ", 2);
	perror(args[0]);
	exit(127);
}

void	execute_cmd2(char *outfile, int *pipefd, char **args, char **envp)
{
	int	fd;

	fd = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		perror_exit(outfile);
	if (dup2(pipefd[0], STDIN_FILENO) < 0)
		perror_exit("dup2");
	if (dup2(fd, STDOUT_FILENO) < 0)
		perror_exit("dup2");
	close(fd);
	close(pipefd[0]);
	close(pipefd[1]);
	if (!args || !args[0])
	{
		ft_putstr_fd("pipex: invalid command\n", 2);
		exit(127);
	}
	execve(args[0], args, envp);
	ft_putstr_fd("pipex: ", 2);
	perror(args[0]);
	exit(127);
}
