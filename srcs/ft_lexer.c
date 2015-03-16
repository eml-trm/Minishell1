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
	char	**arg;
	int		i;

	i = 0;
	list = NULL;
	arg = ft_strsplit(line, ' ');
	while (arg[i])
	{
		ft_add_lex(&list, arg[i]);
		i++;
	}
	ft_parser(&list, line);
	// ft_print_lex(list);
}
