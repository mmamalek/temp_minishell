/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 10:05:50 by pntsunts          #+#    #+#             */
/*   Updated: 2020/07/09 14:32:33 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	envLen(char **Data)
{
	int x;

	x = 0;
	while (Data[x] != NULL)
	{
		x++;
	}
	return (x);
	ft_putnbr(x);
}

void env_setup(char *str, char *envval)
{
	int run;

	char *tmp;
	run = envLen(Data);
	ft_putnbr(run);
	//ft_putendl(str);
	tmp = ft_strjoin(str, ft_strjoin("=", envval));
	ft_putendl(tmp);
}



int checkStr(char **str)
{
	if (envLen(str) != 3)
	{
		ft_putendl("setenv : \033[0mtoo few or many arguments\36m ");
		return (1);
	}
	env_setup(str[1], str[2]);
	return (0);
}
