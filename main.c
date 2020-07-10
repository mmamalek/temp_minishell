/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 08:14:14 by pntsunts          #+#    #+#             */
/*   Updated: 2020/07/09 14:40:35 by pntsunts         ###   ########.fr       */
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

	if (!str || !*str || !**str || str[0] == NULL)
		return (1);
	else if (ft_strcmp(*str, "echo") == 0)
	{
		ft_putendl("HELLO");
		return (1);
	}
	else if (ft_strcmp(*str, "env") == 0)
	{
		printData();
		return (1);
	}
	else if (ft_strcmp(*str, "setenv") == 0)
		return (checkStr(str));	
	return (0);
}

static void readFiles(char **arg)
{
	char *str;
	char **split;
	int run;
	pid_t process;

	run = 1;

	while (run)
	{
		ft_putstr("Wethinkcode\033[32m$>\033[36m ");
		str = getLines();
		process = fork();
		if (process == 0)
		{
			split = ft_strsplit(str, ' ');
			run = check_args(split);
			if (execve(split[0], split, arg) == -1)
				exit(-1);
		}
		if (process > 0)
			wait(&process);
		if (ft_strcmp(str, "exit") == 0)
			exit(0);
}
}

static void getData(char **str)
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
	//ft_putendl(Data[31]);
}

int main(int ac, char **av, char **str)
{
	(void)ac;
	(void)av;
	getData(str);
	readFiles(str);
	return (0);
}
