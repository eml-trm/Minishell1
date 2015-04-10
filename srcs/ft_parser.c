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
	cmd[(ft_count_word(tmp->word) + 1)] = NULL;
}

void	ft_parser(t_lex *list, char **arg)
{
	char	**env;
	t_env	*tempo;
	int		num_cmd;

	tempo = ft_singleton()->env;
	env = init_tab(tempo);
	if (list)
	{
		num_cmd = ft_find_command(list);
		if (num_cmd == 1)
			ft_exec_fork(list, env, arg);
		else if (num_cmd > 1)
			ft_exec_cmd(arg, num_cmd);
		else if (num_cmd == 0)
			code_erreur(2, list->word);
	}
}
