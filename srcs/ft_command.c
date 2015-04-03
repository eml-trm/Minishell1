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
#include <dirent.h>
#include "ft_sh1.h"

// int		ft_find_command(t_lex *lst)
// {
// 	DIR				*dir;
// 	struct dirent	*ret;
// 	int				find;

// 	if (access("/bin", R_OK) != 0)
// 		exit(1);
// 	if (!(dir = opendir("/bin")))
// 		ft_putstr("sh error : can't open dir \n");
// 	while ((ret = readdir(dir)))
// 	{
// 		if (ft_strcmp(lst->word, ret->d_name) == 0)
// 		{
// 			find = 1;
// 			return (find);
// 		}
// 		else
// 			find = 0;
// 	}
// 	return (find);
// }

int		ft_find_command(t_lex *lst, t_env *env)
{
	int				find;

// -> verif: si cmd passee est -> : builtin / pwd/ls / ./-> access 
	find = verif_path(lst, env);
// -> si find == 0 => builtin ou ./
	if (find == 0)
	{
		if (ft_strcmp(lst->word, "exit") == 0)
			find = 0;
		if (ft_strcmp(lst->word, "cd") == 0)
			find = 2;
	}
	return (find);
}

void	ft_exec_cmd(t_lex *list, char **env, char *line)
{
	t_lex	*tmp;
	char	**arg;
	int		i;

	i = 0;
	tmp = list;
	arg = ft_strsplit(line, ' ');
	if (recup_dir(tmp) != NULL)
		execve(ft_strcjoin(recup_dir(tmp), tmp->word, '/'), arg, env);
	else
		code_erreur(2, tmp->word);
}
