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
#include <signal.h>
#include "ft_sh1.h"

int		verif_path(t_lex *lst, t_env *env)
{
	char	**tmp;
	char	**tab;
	int		find;
	int		a;

	a = 0;
	find = 0;
	tmp = ft_strsplit(env->data, '=');
	tab = ft_strsplit(tmp[0], ':');
	while (tab[a])
	{
		tab[a] = ft_strcjoin(tab[a], lst->word, '/');
		if (access(tab[a], X_OK) == 0)
		{
			find = 1;
			a++;
		}
		else
			a++;
	}
	return (find);
}


void		ft_find_arg(t_lex *list)
{
	int		i;
	char	**cmd;
	t_lex	*tmp;

	i = 0;
	tmp = list;
	cmd = (char **)malloc(sizeof(char *) * (ft_count_word(tmp->word) + 1));
	while (tmp)
	{
		cmd[i] = (char *)malloc(sizeof(char) * ft_strlen(tmp->word) + 1);
		cmd[i] = tmp->word;
		i++;
		tmp = tmp->next;
	}
	cmd[i] = NULL;
}



void	ft_parser(t_lex **list, char *line)
{
	t_lex	*tmp;
	char	**env;
	t_env	*tempo;
	int		num_cmd;

	ft_print_color(YELLOW, "parser\n", 1);
	tempo = ft_singleton()->env;
	env = init_tab(tempo);
	tmp = *list;
	if (tmp)
	{
		num_cmd = ft_find_command(tmp, tempo);
		if (num_cmd > 0)
			ft_exec_fork(tmp, env, line, num_cmd);
		// if (ft_strcmp(ft_strtrim(line), "exit") == 0)
		// 	exit(1);
	}
}
