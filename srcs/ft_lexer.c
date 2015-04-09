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

char	**ft_split(char *line)
{
	int		i;
	int		a;
	int		b;
	char	**tab;

	i = -1;
	a = 0;
	b = 0;
	tab = (char **)malloc(sizeof(char *) * ft_count_word(line) + 1);
	tab[(ft_count_word(line) + 1)] = NULL;
	tab[a] = (char *)malloc(sizeof(char) * ft_strlen(line) + 1);
	while (line[++i])
		if (line[i] != ' ' && line[i] != '\t')
			tab[a][b++] = line[i];
		else
		{
			tab[a++][b] = '\0';
			b = 0;
			tab[a] = (char *)malloc(sizeof(char) * ft_strlen(line) + 1);
		}
	tab[a][b] = '\0';
	return (tab);
}

void	ft_print_lex(t_lex *lex)
{
	t_lex	*tmp;

	tmp = lex;
	ft_print_color(GREEN, "lex :\n", 1);
	while (tmp)
	{
		ft_putstr(tmp->word);
		ft_putchar('\n');
		tmp = tmp->next;
	}
	ft_print_color(GREEN, "fin de lex \n", 1);
}

void	ft_lexer(char *line)
{
	t_lex	*list;
	char	**arg;
	int		i;

	i = 0;
	list = NULL;
	arg = ft_split(ft_strtrim(line));
	while (arg[i])
	{
		ft_add_lex(&list, arg[i]);
		i++;
	}
	ft_parser(&list, arg);
}