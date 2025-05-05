/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kato <kato@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:44:52 by kato              #+#    #+#             */
/*   Updated: 2025/05/05 18:44:56 by kato             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	run_pipex(char **argv, char **envp)
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;
	char	*cmd1_args[4];
	char	*cmd2_args[4];

	if (pipe(pipefd) == -1)
		perror_exit("pipe");
	setup_cmd_args(cmd1_args, argv[2]);
	setup_cmd_args(cmd2_args, argv[3]);
	pid1 = fork();
	if (pid1 < 0)
		perror_exit("fork");
	if (pid1 == 0)
		execute_cmd1(argv[1], pipefd, cmd1_args, envp);
	pid2 = fork();
	if (pid2 < 0)
		perror_exit("fork");
	if (pid2 == 0)
		execute_cmd2(argv[4], pipefd, cmd2_args, envp);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
	{
		ft_putstr_fd("Usage: ./pipex file1 cmd1 cmd2 file2\n", 2);
		return (1);
	}
	run_pipex(argv, envp);
	return (0);
}
