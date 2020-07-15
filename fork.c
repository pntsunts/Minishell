/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 12:17:42 by pntsunts          #+#    #+#             */
/*   Updated: 2020/07/15 16:34:34 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*static int path_man(char **str, char **path)
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
				forking(tmp2, path);
				free(tmp2);
				return (1);
			}
		}
		free(tmp2);
	}
	return (0);
}*/

int forking(char *str, char **arg)
{
	pid_t pid;
	
	if (access(str, F_OK) != 0)
	{
		ft_putstr("Command not found : ");
		ft_putendl(str);
	}
	pid = fork();

	if (pid == 0)
	{
		execve(&str[0], arg, Data);
	}
	wait(&pid);
	return (1);
}

/*int exe(char **str)
{
	struct stat fstat;
	char **path;
	int i = 0;

	if (lstat(str[0], &fstat) != -1)
	{
		if (fstat.st_mode & S_IXUSR)
		{
			forking(str[0], str);
			return (1);
		}
	}
	path = ft_strsplit(Get_cd("PATH"), ':');
	if (!path)
		return (1);
	else
	{
		i = path_man(str, path);
	}
	free(path);
	return (1);
}*/

