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

void	ft_parser(t_lex **list)
{
	t_lex	*tmp;
	char	**tab;
	t_env	*tempo;

	tempo = ft_singleton()->env;
	tab = init_tab(tempo);
	printf("TAB\n");
	tmp = *list;
	// if (ft_find_command(tmp) == 1)
	// 	execve(ft_strcat("/bin/", tmp->word), &tmp->next->word, tab);
}
