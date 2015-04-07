/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 18:12:00 by etermeau          #+#    #+#             */
/*   Updated: 2015/03/13 18:12:02 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
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
	char	*word;
	char	**tab;
	t_env	*tmp;

	a = 0;
	tab = (char **)malloc(sizeof(char *) * (count_chain(list) + 1));
	tab[(count_chain(list) + 1)] = NULL;
	tmp = list;
	while (tmp)
	{
		word = ft_strjoin(tmp->name, tmp->data);
		tab[a] = (char *)malloc(sizeof(char) * (ft_strlen(word) + 1));
		tab[a] = word;
		a++;
		tmp = tmp->next;
	}
	return (tab);
}

void	ft_print_tab(char **tab)
{
	int 	i;

	i = 0;
	while (tab[i])
	{
		ft_putstr("tab[i] = ");
		ft_putendl(tab[i]);
		i++;
	}
}
