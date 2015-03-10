/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 12:03:54 by etermeau          #+#    #+#             */
/*   Updated: 2015/03/09 12:03:55 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void	ft_exit(int status)
{
	t_glob	*glob;
	t_env	*tmp;

	(void)status;
	glob = ft_singleton();
	tmp = glob->env;
	while (tmp)
	{
		free(tmp->name);
		free(tmp->data);
		tmp = tmp->next;
	}
	glob->ret = status;
	free(glob);
	while (1);
}
