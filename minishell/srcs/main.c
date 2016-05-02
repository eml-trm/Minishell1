/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 21:50:13 by etermeau          #+#    #+#             */
/*   Updated: 2015/02/26 21:50:15 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "ft_sh1.h"

void		init_void_env(t_env **list)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = NULL;
	if (!(tmp = (char **)malloc(sizeof(char *))))
		code_erreur(2, NULL);
	tmp[0] = "PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/opt/X11/bin";
	tmp[1] = "TERM=xterm-256color";
	tmp[2] = "ITERM_PROFILE=Default";
	tmp[3] = "TERM_PROGRAM=iTerm.app";
	while (i < 4)
	{
		ft_add_elem(list, tmp[i]);
		i++;
	}
	free(tmp);
}

void		ft_sh(char **av, char **envp)
{
	char	*line;
	int		i;
	t_env	*tmp;

	i = 0;
	ft_singleton();
	(void)av;
	tmp = NULL;
	while (envp[i])
	{
		ft_add_elem(&tmp, envp[i]);
		i++;
	}
	if (!*envp)
		init_void_env(&tmp);
	ft_singleton()->env = tmp;
	line = NULL;
	while (42)
	{
		ft_print_magenta("# shell #> ");
		get_next_line(0, &line);
		if (line && line[0] != '\n')
			ft_lexer(line);
	}
}

int			main(int ac, char **av, char **envp)
{
	if (ac == 1)
		ft_sh(av, envp);
	return (ft_singleton()->ret);
}
