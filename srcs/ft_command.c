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
#include "ft_sh1.h"

void	ft_command(t_env *env, char *line)
{
	t_env	*top;
	char	*tmp;
	char 	*tmp_2;
	int		status;

	top = env;
	tmp = ft_strcdup(line, ' ');
	tmp_2 = ft_strchr(line, ' ');
	free(line);
	if (ft_strcmp(tmp, "env") == 0)
		ft_print_list(env);
	if (ft_strcmp(tmp, "setenv") == 0)
	{
		ft_add_elem(&top, tmp_2);
	}
	if (ft_strcmp(tmp, "exit") == 0)
	{
		status = 0;
		ft_exit(status);
	}
}
