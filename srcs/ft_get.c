/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 14:42:41 by etermeau          #+#    #+#             */
/*   Updated: 2015/03/04 14:42:45 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // getcwd
#include "ft_sh1.h"

char		*ft_getenv(char *name)
{
	t_env	*tmp;
	char	**path;

	tmp = ft_singleton()->env;
	while (tmp)
	{
		path = ft_strsplit(tmp->data, '=');
		if (ft_strcmp(name, tmp->name) == 0)
			return (path[0]);
		tmp = tmp->next;
	}
	return (NULL);
}

char		*ft_getcwd(void)
{
	char	*path;
	int		i;

	i = 1;
	while (42)
	{
		path = NULL;
		if (!(path = (char *)malloc(i * sizeof(path))))
			return (NULL);
		if (getcwd(path, i))
		{
			path = ft_strjoin("=", path);
			return (path);
		}
		if (path)
			free(path);
		i += 1;
		if (i > 255)
			return (NULL);
	}
}