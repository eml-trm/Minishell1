/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binaries.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 18:26:41 by etermeau          #+#    #+#             */
/*   Updated: 2015/04/03 18:26:42 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_sh1.h"

char		**bin(char *cmd, char *path_env)
{
	char	**path;
	char	**temp;

	if (!path_env)
		return (ft_strsplit(cmd, ' '));
	path = ft_strsplit(path_env, ':');
	temp = path;
	path_env = NULL;
	while (*temp)
	{
		path_env = ft_strjoin(*temp, "/");
		free(*temp);
		*temp = ft_strjoin(path_env, cmd);
		free(path_env);
		path_env = NULL;
		temp++;
	}
	return (path);
}
