/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 14:42:41 by etermeau          #+#    #+#             */
/*   Updated: 2015/03/04 14:42:45 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <dirent.h>
#include <signal.h>
#include "ft_sh1.h"

int		verif_path(t_lex *lst)
{
	char	*tmp;
	char	**tab;
	int		find;
	int		a;

	a = 0;
	find = 0;
	tmp = ft_getenv("PATH");
	tab = ft_strsplit(tmp, ':');
	while (tab[a])
	{
		tab[a] = ft_strcjoin(tab[a], lst->word, '/');
		if (access(tab[a], X_OK) == 0)
			find = 1;
		a++;
	}
	return (find);
}

int		ft_find_command(t_lex *lst)
{
	int		find;
	char	*cmd;

	ft_print_color(BLUE, "CHECK_CMD\n", 1);
	cmd = lst->word;
	find = 0;
	if (ft_strcmp(cmd, "cd") == 0)
		find = 2;
	else if (ft_strcmp(cmd, "env") == 0)
		find = 3;
	else if (ft_strcmp(cmd, "setenv") == 0)
		find = 4;
	else if (ft_strcmp(cmd, "unsetenv") == 0)
		find = 5;
	else if (ft_strcmp(cmd, "exit") == 0)
		find = 6;
	else
		find = verif_path(lst);
	printf("find = %d\n", find);
	return (find);
}

void	ft_exec_cmd(char **arg, int cmd)
{
	if (cmd == 2)
		ft_cd(arg);
	else if (cmd == 3)
		ft_env(arg);
	else if (cmd == 4)
		ft_setenv(arg);
	else if (cmd == 5)
		ft_unsetenv(arg);
	else if (cmd == 6)
		ft_exit(arg);
}
