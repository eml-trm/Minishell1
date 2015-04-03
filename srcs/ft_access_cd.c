/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_access_cd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 17:48:03 by etermeau          #+#    #+#             */
/*   Updated: 2015/03/31 17:48:04 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <unistd.h> // chdir
#include "ft_sh1.h"

// static void	ft_set_pwd(void)
// {
// 	char	*new_path;

// 	new_path = NULL;
// 	new_path = ft_getcwd();
// 	set_glob("OLDPWD", glob()->pwd, 6);
// 	set_glob("PWD", new_path, 3);
// 	if (new_path)
// 	{
// 		free(new_path);
// 		new_path = NULL;
// 	}
// }

int			ft_access(char *path)
{
	struct stat	file;

	if (access(path, F_OK) == -1)
	{
		code_erreur(3, path);
		return (0);
	}
	stat(path, &file);
	if (file.st_mode & S_IFDIR)
	{
		if (chdir(path) < 0)
			code_erreur(4, path);
		// else
		// 	ft_set_pwd();
	}
	else
		code_erreur(5, path);
	return (0);
}

