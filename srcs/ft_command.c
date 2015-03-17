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
#include "ft_sh1.h"

void	ft_exec_fork(t_lex *list, char **env, char *line)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		ft_command(list, env, line);
	else
		wait(NULL);
}

void	ft_command(t_lex *list, char **env, char *line)
{
	t_lex	*tmp;
	char	**arg;
	int		i;

	i = 0;
	tmp = list;
	arg = ft_strsplit(line, ' ');

	execve(ft_strjoin("/bin/", tmp->word), arg, env);
}
