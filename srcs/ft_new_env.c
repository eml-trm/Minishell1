/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 18:12:51 by etermeau          #+#    #+#             */
/*   Updated: 2015/04/03 18:12:53 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_sh1.h"

static int	count_env(t_env *env)
{
	int	i;

	i = 0;
	while (env)
	{
		i++;
		env = env->next;
	}
	return (i);
}

static int	copy_env(char ***new_env, t_env *env)
{
	char	**temp;
	char	*join;

	temp = *new_env;
	join = NULL;
	while (env)
	{
		if (!(join = ft_strdup(env->name)))
			return (1);
		if (!(*temp = ft_strjoin(join, env->data)))
			return (1);
		free(join);
		env = env->next;
	}
	return (0);
}

char		**build_env(t_env *env)
{
	int		i;
	char	**new_env;

	i = count_env(env);
	if (!(new_env = ft_memalloc(sizeof(char **) * (i + 1))))
		return (NULL);
	copy_env(&new_env, env);
	return (new_env);
}
