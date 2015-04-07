/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/05 18:00:24 by etermeau          #+#    #+#             */
/*   Updated: 2015/04/05 18:00:25 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "ft_sh1.h"

static void	ft_del_elem(t_env *elem, t_env *start, int i)
{
	t_env	*av1;
	t_env	*av2;

	if (i < 1)
	{
		av1 = elem;
		av2 = elem->next;
		free(&av1->name);
		av1->name = NULL;
		av1->data = NULL;
		av2 = start->next;
		ft_singleton()->env = av2;
	}
	else
	{
		av1 = elem;
		av2 = elem->next;
		free(&av2->name);
		av2->name = NULL;
		av2->data = NULL;
		if (av2->next == NULL)
			av1->next = NULL;
		else
			av1->next = av2->next;
	}
}

void	ft_unsetenv(char **str)
{
	t_env	*tmp;
	int		i;

	i = 0;
	if (str[2])
		code_erreur(8, "unsetenv");
	tmp = ft_singleton()->env;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, str[1]) == 0)
			break;
		tmp = tmp->next;
		i++;
	}
	tmp = ft_singleton()->env;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	ft_del_elem(tmp, ft_singleton()->env, i);
}

void	ft_setenv(char **str)
{
	t_env *tmp;
	char	*arg;

	tmp = ft_singleton()->env;
	while (tmp)
	{
		tmp = tmp->next;
	}
	if (str[2] == NULL)
		code_erreur(7, "setenv");
	arg = ft_strjoin("=", str[2]);
	ft_new_env(str[1], arg, ft_strlen(str[1]));
}

void	ft_env(char **str)
{
	(void)str;
	ft_print_env(ft_singleton()->env);
}
