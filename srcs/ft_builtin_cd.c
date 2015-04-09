/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 12:03:54 by etermeau          #+#    #+#             */
/*   Updated: 2015/03/09 12:03:55 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include "ft_sh1.h"

static char	*istild(char **str)
{
	char	*temp;
	char	*tmp;
	char	*path;

	temp = *str;
	if (!ft_strncmp(temp, "~/", 2))
	{
		tmp = NULL;
		tmp = ft_strdup(ft_getenv("HOME"));
		if (!tmp)
			return (*str);
		path = ft_strjoin(tmp, *(str) + 1);
		if (tmp)
			free(tmp);
		tmp = NULL;
		if (str)
			free(*str);
		*str = path;
	}

	return (*str);
}

void	ft_cd(char **cmd)
{
	char	*path;

	path = NULL;
	if (!cmd[1] || (!ft_strncmp(cmd[1], "~", 2) && !cmd[2]))
		path = ft_strdup(ft_getenv("HOME"));
	else if (!ft_strcmp(cmd[1], "-") && !cmd[2])
		path = ft_strdup(ft_getenv("OLDPWD"));
	else if (!cmd[2])
		path = ft_strdup(istild(&cmd[1]));
	else
		code_erreur(6, NULL);
	if (path)
	{
		if (ft_singleton()->pwd)
			free(ft_singleton()->pwd);
		ft_singleton()->pwd = ft_getcwd();
		ft_access(path);
	}
	if (path)
		free(path);
}
