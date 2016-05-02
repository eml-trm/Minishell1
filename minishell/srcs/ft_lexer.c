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

#include "ft_sh1.h"

static char *ft_malloc(char *str, char *line)
{
	if (!(str = (char *)malloc(sizeof(char) * ft_strlen(line) + 1)))
		code_erreur(0, NULL);
	return (str);
}

char		**ft_split(char *line, int a, int b, int i)
{
	char	**tab;

	if (!(tab = (char **)malloc(sizeof(char *) * ft_count_word(line) + 1)))
		code_erreur(0, NULL);
	tab[a] = ft_malloc(tab[a], line);
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	while (line[i])
	{
		while (line[i] && line[i] != ' ' && line[i] != '\t')
		{
			tab[a][b++] = line[i++];
			tab[a][b] = '\0';
		}
		if (line[i])
		{
			a++;
			b = 0;
			tab[a] = ft_malloc(tab[a], line);
			while (line[i] && (line[i] == ' ' || line[i] == '\t'))
				i++;
		}
	}
	tab[ft_count_word(line)] = NULL;
	return (tab);
}

void		ft_print_lex(t_lex *lex)
{
	t_lex	*tmp;

	tmp = lex;
	while (tmp)
	{
		ft_putstr(tmp->word);
		ft_putchar('\n');
		tmp = tmp->next;
	}
}

void		ft_lexer(char *line)
{
	t_lex	*list;
	char	**arg;
	int		i;

	i = 0;
	list = NULL;
	arg = ft_split(line, 0, 0, 0);
	while (arg[i])
	{
		ft_add_lex(&list, arg[i]);
		i++;
		if (i == 10)
			break ;
	}
	if (list)
		ft_parser(list, arg);
}
