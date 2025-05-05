/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kato <kato@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:02:27 by kato              #+#    #+#             */
/*   Updated: 2025/05/05 18:37:06 by kato             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	setup_cmd_args(char **cmd_args, const char *cmd)
{
	cmd_args[0] = "/bin/sh";
	cmd_args[1] = "-c";
	cmd_args[2] = (char *)cmd;
	cmd_args[3] = NULL;
}

void	perror_exit(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}
