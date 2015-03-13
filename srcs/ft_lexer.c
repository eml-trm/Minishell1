/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 16:35:29 by etermeau          #+#    #+#             */
/*   Updated: 2015/03/10 16:35:31 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "ft_sh1.h"

// void	ft_print_lex(t_lex *lex)
// {
// 	t_lex	*tmp;

// 	tmp = lex;
// 	while (tmp)
// 	{
// 		ft_putstr(tmp->word);
// 		ft_putchar('\n');
// 		tmp = tmp->next;
// 	}
// }

void	ft_lexer(char *line)
{
	t_lex	*list;
	char	**tab;
	int		i;

	i = 0;
	list = NULL;
	tab = ft_strsplit(line, ' ');
	while (tab[i])
	{
		ft_add_lex(&list, tab[i]);
		i++;
	}
	ft_parser(&list);
	// ft_print_lex(list);
}
