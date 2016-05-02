/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_access.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 18:32:15 by etermeau          #+#    #+#             */
/*   Updated: 2015/04/03 18:32:16 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "ft_sh1.h"

static int	isexec(char *tmp, int key)
{
	struct stat	file;

	if (!access(tmp, X_OK))
	{
		stat(tmp, &file);
		if (file.st_mode & S_IFREG)
			return (0);
		ft_putstr_fd("sh: is not a exec file\n", 2);
		if (key)
			return (5);
		exit(5);
	}
	return (1);
}

int			isexist(char *tmp, int type, int key)
{
	if (!access(tmp, F_OK))
	{
		if (!isexec(tmp, key))
			return (0);
		else
			code_erreur(1, tmp);
		if (key)
			return (6);
		exit(6);
	}
	else if (!type)
	{
		code_erreur(3, tmp);
		if (key)
			return (7);
		exit(7);
	}
	return (1);
}

int			isaccess(char **cmd, int type, int key)
{
	char		**tmp;
	int			i;

	i = 0;
	tmp = cmd;
	while (tmp[i])
	{
		if (!isexist(tmp[i], type, key))
			return (i);
		else
			i++;
	}
	return (-1);
}
