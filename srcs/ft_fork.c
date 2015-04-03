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
#include "ft_sh1.h"

char	*recup_dir(t_lex *lst)
{
	t_env	*tmp;
	char	**hlp;
	char	**tab;
	int		a;

	a = 0;
	tmp = ft_singleton()->env;
	hlp = ft_strsplit(tmp->data, '=');
	tab = ft_strsplit(hlp[0], ':');
	while (tab[a])
	{
		if (access(ft_strcjoin(tab[a], lst->word, '/'), X_OK) == 0)
			return (tab[a]);
		else
			a++;
	}
	return (NULL);
}

void	ft_exec_fork(t_lex *list, char **env, char *line)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		ft_exec_cmd(list, env, line);
	else
		wait(NULL);
}
