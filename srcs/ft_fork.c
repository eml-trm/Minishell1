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
	char	*tmp;
	char	**tab;
	int		a;

	a = 0;
	tmp = ft_getenv("PATH");
	tab = ft_strsplit(tmp, ':');
	while (tab[a])
	{
		tab[a] = ft_strcjoin(tab[a], lst->word, '/');
		if (access(tab[a], X_OK) == 0)
			return (tab[a]);
		else
			a++;
	}
	return (NULL);
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
		execve(dir, arg, env);
	else
		wait(NULL);
}


// -wait recupere la valeur de retour de execve -> a mettre dans une focntin pour valeur de singleton->ret
