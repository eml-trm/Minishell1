/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 12:18:39 by etermeau          #+#    #+#             */
/*   Updated: 2015/03/07 12:18:41 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void	ft_add_elem(t_env **list, char *name)
{
	t_env	*new;
	t_env	*tmp;

	new = ft_new_elem(name);
	tmp = NULL;
	if (*list == NULL)
		*list = new;
	else
	{
		tmp = (*list);
		while (tmp)
		{
			if (!(tmp->next))
				break ;
			tmp = tmp->next;
		}
		tmp->next = new;
	}
}

t_env	*ft_new_elem(char *elem)
{
	t_env	*tmp;

	tmp = (t_env *)malloc(sizeof(t_env));
	tmp->name = ft_strcdup(elem, '=');
	tmp->data = ft_strchr(elem, '=');
	tmp->next = NULL;
	return (tmp);
}
