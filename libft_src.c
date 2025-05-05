/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_src.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kato <kato@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:25:52 by kato              #+#    #+#             */
/*   Updated: 2025/05/05 18:27:18 by kato             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <string.h>

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, strlen(s));
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*res;

	len = strlen(s1) + strlen(s2);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	strcpy(res, s1);
	strcat(res, s2);
	return (res);
}
