/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 14:58:07 by etermeau          #+#    #+#             */
/*   Updated: 2015/03/31 14:58:09 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include "ft_sh1.h"

char	*recup_dir(t_lex *lst)
{
	char	*tmp;
	char	**tab;
	int		a;

	a = 0;
	tmp = ft_getenv("PATH");
	tab = ft_strsplit(tmp, ':');
	while (tab[a])
	{
		tmp = ft_strcjoin(tab[a], lst->word, '/');
		if (access(tmp, X_OK) == 0)
		{
			ft_free_tab(tab);
			return (tmp);
		}
		else
			a++;
	}
	return (NULL);
}

void	ft_exec_bin(char **arg, char **env)
{
	if (access(*arg, F_OK) == 0)
	{
		if (access(*arg, X_OK) == 0)
		{
			execve(*arg, arg, env);
			exit(0);
		}
		code_erreur(1, NULL);
	}
	else
		code_erreur(2, *arg);
}

void	ft_exec_fork(t_lex *list, char **env, char **arg)
{
	pid_t	pid;
	t_lex	*tmp;
	char	*dir;

	tmp = list;
	dir = recup_dir(tmp);
	pid = fork();
	if (pid == 0)
	{
		if (ft_strchr(*arg, '/'))
			ft_exec_bin(arg, env);
		else
		{
			execve(dir, arg, env);
			code_erreur(10, NULL);
			exit(0);
		}
	}
	else
		wait(NULL);
}