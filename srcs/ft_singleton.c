/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_singleton.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 14:30:55 by etermeau          #+#    #+#             */
/*   Updated: 2015/03/09 14:30:57 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

t_glob	*ft_singleton(void)
{
	static t_glob	*glob = NULL;

	if (!glob)
	{
		if (!(glob = (t_glob *)malloc(sizeof(t_glob))))
			ft_putstr("Malloc error\n");
		glob->env = NULL;
		glob->ret = 0;
		glob->next = NULL;
	}
	return (glob);
}
