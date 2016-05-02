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

#include "ft_sh1.h"

static int	check_name(char *str)
{
	t_env	*env;
	int		find;

	find = 0;
	env = ft_singleton()->env;
	while (env)
	{
		if (ft_strcmp(env->name, str) == 0)
			find = 1;
		env = env->next;
	}
	if (find == 0)
		return (1);
	return (0);
}

int			ft_unsetenv(char **str)
{
	t_env	*tmp;
	int		i;

	i = 0;
	if (str[2])
		code_erreur(8, "unsetenv");
	tmp = ft_singleton()->env;
	if (check_name(str[1]) == 1)
		return (1);
	while (tmp)
	{
		if (ft_strcmp(tmp->name, str[1]) == 0)
			break ;
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
	return (0);
}

void		ft_setenv(char **str)
{
	t_env	*tmp;
	char	*arg;

	tmp = ft_singleton()->env;
	while (tmp)
	{
		tmp = tmp->next;
	}
	if (str[3] || str[1] == NULL)
		code_erreur(7, "setenv");
	else
	{
		if (ft_strchr(str[1], '='))
			code_erreur(12, NULL);
		else
		{
			if (!str[2])
				arg = "=";
			else
				arg = ft_strjoin("=", str[2]);
			ft_new_env(str[1], arg, ft_strlen(str[1]));
		}
	}
}
