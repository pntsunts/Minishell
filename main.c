/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 08:14:14 by pntsunts          #+#    #+#             */
/*   Updated: 2020/07/15 16:54:32 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	dataLen(char **str)
{
	int i;

	i = 0;
	while (str[i] != NULL)
	{
		i++;
	}
	return (i);
}

static char *getLines()
{
	char *line;
	line = NULL;
	get_next_line(0, &line);
	return (line);
}

static void printData()
{
	int i;

	i = 0;
	while (Data[i])
	{
		ft_putendl(Data[i]);
		i++;
	}
}

static int check_args(char **str)
{
	int run;

	run = 1;

	if (!str || !*str || !**str || str[0] == NULL)
	{
		return (1);
	}
	else if (ft_strcmp(*str, "exit") == 0)
	{
		return (0);
	}
	else if (ft_strcmp(*str, "env") == 0)
	{
		printData();
		return (1);
	}
	else if (ft_strcmp(*str, "setenv") == 0)
	{
		checkStr(str);
		return (1);
	}
	else if (ft_strcmp(*str, "unset") == 0)
	{
		check(str);
		return (1);
	}
	else if (ft_strcmp(*str, "echo") == 0)
	{
		ft_echo(str);
		return (1);
	}
	else if (ft_strcmp(*str, "pwd") == 0)
	{
		pwd();
		return (1);
	}
	else  if (ft_strcmp(*str, "cd") == 0)
	{
		cd(str[1]);
		//set_cd(str);
		return (1);
	}
	return (forking(str[0], str));
	//return (exe(str));
}

static void	readFiles(void)
{
	char	*str;
	char	**arg;
	int		run;

	run = 1;
	while (run)
	{
		ft_putstr("Wethinkcode\033[32m$>\033[36m ");
		str = getLines();
		arg = split(str);
		free(str);
		run = check_args(arg);
	}
}

static void  getData(char **str)
{
	int i;

	i = 0;
	
	Data = (char **)malloc(sizeof(char *) * (dataLen(str) + 1));

	while (str[i])
	{
		Data[i] = ft_strdup(str[i]);
		i++;
	}
	Data[i] = NULL;
}

int main(int ac, char **av, char **str)
{
	(void)ac;
	(void)av;
	getData(str);
	readFiles();
	//sleep(10);
	return (0);
}

