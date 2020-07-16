/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 15:25:22 by pntsunts          #+#    #+#             */
/*   Updated: 2020/07/16 17:12:00 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int in_exec(char *str, char **arg)
{
	pid_t pid;
	
	pid = fork();

	if (pid == 0)
	{
		execve(&str[0], arg, Data);
	}
	wait(&pid);
	return (1);
}

static int man_path(char **str, char **path)
{
	int i;
	struct stat fstat;

	char *tmp2;


	i = -1;
	while (path[++i])
	{
		tmp2 = ft_strjoin(path[i], ft_strjoin("/", str[0]));
		if (lstat(tmp2, &fstat) != -1)
		{
			if (fstat.st_mode & S_IXUSR)
			{
				in_exec(tmp2, path);
				free(tmp2);
				return (1);
			}
		}
		free(tmp2);
	}
	return (0);
}

int bin(char **str)
{
	int i = 0;
	char **path;
	if (access(str[0], F_OK) != 0)
	{
		ft_putstr("command not found :");
		ft_putendl(str[0]);
	}
	in_exec(str[0], str);
	path = ft_strsplit(Get_cd("PATH"), ':');
	if (!path )
		return (1);
	else
		i = man_path(str, path);
	return (1);
}
