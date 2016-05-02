/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 18:12:00 by etermeau          #+#    #+#             */
/*   Updated: 2015/04/11 20:08:22 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_sh1.h"

int		count_chain(t_env *list)
{
	int		i;
	t_env	*tmp;

	i = 0;
	tmp = list;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

char	**init_tab(t_env *list)
{
	int		a;
	char	**tab;
	t_env	*tmp;

	a = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * (count_chain(list) + 1))))
		code_erreur(0, NULL);
	tmp = list;
	while (tmp)
	{
		tab[a] = ft_strjoin(tmp->name, tmp->data);
		a++;
		tmp = tmp->next;
	}
	tab[a] = NULL;
	return (tab);
}

void	ft_free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	tab[i] = NULL;
}

void	ft_print_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		ft_putstr("tab[i] = ");
		ft_putendl(tab[i]);
		i++;
	}
}
