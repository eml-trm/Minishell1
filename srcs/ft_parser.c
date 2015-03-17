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
#include "ft_sh1.h"

// char		*ft_recup_path(void)
// {
// 	t_env	*env;
// 	char	*tmp;
// 	char	*path;

// 	env = ft_singleton()->env;
// 	while (env)
// 	{
// 		if (ft_strcmp(env->name, "PATH") == 0)
// 			tmp = env->data;
// 		env = env->next;
// 	}
// 	path = ft_strchr(tmp, '/');
// 	printf("path = %s\n", path);
// 	return (path);
// }

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
	cmd[i] = NULL;
}

int		ft_find_command(t_lex *lst)
{
	DIR				*dir;
	struct dirent	*ret;
	int				find;

	if (access("/bin", R_OK) != 0)
		exit(1);
	if (!(dir = opendir("/bin")))
		ft_putstr("sh error : can't open dir \n");
	while ((ret = readdir(dir)))
	{
		if (ft_strcmp(lst->word, ret->d_name) == 0)
		{
			find = 1;
			return (find);
		}
		else
			find = 0;
	}
	return (find);
}

void	ft_parser(t_lex **list, char *line)
{
	t_lex	*tmp;
	char	**env;
	t_env	*tempo;

	tempo = ft_singleton()->env;
	env = init_tab(tempo);
	tmp = *list;
	if (ft_find_command(tmp) == 1)
		ft_exec_fork(tmp, env, line);
	else if (ft_strcmp(ft_strtrim(line), "exit") == 0)
		exit(1);
	else
	{
		ft_putstr("sh: ");
		ft_putstr(tmp->word);
		ft_putendl(": command not found");
	}
}
