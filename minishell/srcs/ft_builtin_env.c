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

#include "ft_sh1.h"

void	add_env(t_env **temp, char *name, char *data)
{
	t_env	*new_env;
	t_env	*c_temp;

	new_env = NULL;
	if (!(new_env = (t_env *)malloc(sizeof(t_env))))
		code_erreur(0, NULL);
	new_env->name = ft_strdup(name);
	new_env->data = ft_strdup(data);
	new_env->next = NULL;
	if (!*temp)
		*temp = new_env;
	else
	{
		c_temp = *temp;
		while (c_temp->next)
			c_temp = c_temp->next;
		c_temp->next = new_env;
	}
}

void	ft_new_env(char *name, char *info, int i)
{
	t_env	*tp;

	tp = ft_singleton()->env;
	while (tp)
	{
		if (ft_strnstr(tp->name, name, i) && ft_strlen(tp->name) == (size_t)i)
		{
			tp->data = ft_strdup(info);
			return ;
		}
		tp = tp->next;
	}
	add_env(&(ft_singleton()->env), name, info);
}

void	ft_del_elem(t_env *elem, t_env *start, int i)
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

void	ft_env(char **str)
{
	if (str[1])
		code_erreur(11, NULL);
	else
		ft_print_env(ft_singleton()->env);
}
