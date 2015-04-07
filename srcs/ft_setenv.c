/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 19:19:17 by etermeau          #+#    #+#             */
/*   Updated: 2015/04/03 19:19:18 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "ft_sh1.h"

void		add_env(t_env **temp, char *name, char *data)
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
	t_env	*temp;

	temp = ft_singleton()->env;
	while (temp)
	{
		if (ft_strnstr(temp->name, name, i) && ft_strlen(temp->name) == (size_t)i)
		{
			temp->data = ft_strdup(info);
			return ;
		}
		temp = temp->next;
	}
	add_env(&(ft_singleton()->env), name, info);
}
