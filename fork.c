/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 12:17:42 by pntsunts          #+#    #+#             */
/*   Updated: 2020/07/15 09:57:34 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	else if (pid < 0)
		ft_putendl("failed");
	wait(&pid);
	return (1);
}

