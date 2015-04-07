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

// int		ft_find_command(t_lex *lst, t_env *env)
// {
// 	int				find;

// 	find = verif_path(lst, env);
// 	if (find == 0)
// 	{
// 		printf("Passage\n");
// 		if (ft_strcmp(lst->word, "cd") == 0)
// 			find = 2;
// 	}
// 	printf("find_after = %d\n", find);
// 	return (find);
// }

int		ft_find_command(t_lex *lst, t_env *env)
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
		find = verif_path(lst, env);
	printf("find = %d\n", find);
	return (find);
}

void	ft_exec_cmd(t_lex *list, char **env, char *line, int cmd)
{
	t_lex	*tmp;
	char	**arg;
	char	*dir;
	int		i;

	i = 0;
	tmp = list;
	dir = recup_dir(tmp);
	arg = ft_strsplit(line, ' ');
	if (dir != NULL && cmd == 1)
		execve(dir, arg, env);
	else if (cmd == 2)
		ft_cd(arg);
	else if (cmd == 3)
		ft_env(arg);
	else if (cmd == 4)
		ft_setenv(arg);
	else if (cmd == 5)
		ft_unsetenv(arg);
	else if (cmd == 6)
		ft_exit(arg);
	else if (cmd == 0)
		code_erreur(2, tmp->word);
}
