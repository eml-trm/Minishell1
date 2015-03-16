/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 15:07:13 by etermeau          #+#    #+#             */
/*   Updated: 2015/03/13 15:07:18 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <dirent.h>
#include "ft_sh1.h"

char		**ft_find_arg(t_lex *list)
{
	int i;
	char	**cmd;
	t_lex	*tmp;
/* essai pour arg, voir si opt et si rep. join ts pour tester dans ls*/
	i = 0;
	tmp = list;
	tmp = tmp->next;
	while (tmp)
	{
		cmd[i] = tmp->word;
		i++;
		tmp = tmp->next;
	}
}

int		ft_find_command(t_lex *lst)
{
	DIR				*dir;
	struct dirent	*ret;
	int				find;

	if (access("/bin", R_OK) != 0)
		exit(1);
	if (!(dir = opendir("/bin")))
		ft_putstr("sh error : can't open dir \n");
	while ((ret = readdir(dir)))
	{
		if (ft_strcmp(lst->word, ret->d_name) == 0)
		{
			find = 1;
			return (find);
		}
		else
			find = 0;
	}
	return (find);
}

void	ft_parser(t_lex **list, char *line)
{
	t_lex	*tmp;
	char	**env;
	char	**arg;
	t_env	*tempo;

	tempo = ft_singleton()->env;
	env = init_tab(tempo);
	tmp = *list;
	if (ft_find_command(tmp) == 1)
		ft_exec_fork(tmp, env);
	else
	{
		ft_putstr("sh: ");
		ft_putstr(tmp->word);
		ft_putendl(": command not found");
	}
}
