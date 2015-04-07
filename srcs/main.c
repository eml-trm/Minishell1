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
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> //open
#include "ft_sh1.h"

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
	ft_singleton()->env = tmp;
	while (ft_singleton()->ret == -1)
	{	
		ft_print_magenta("# shell #> ");
		get_next_line(0, &line);
		if (line)
			ft_lexer(line);
	}
}

int			main(int ac, char **av, char **envp)
{
	if (ac == 1)
		ft_sh(av, envp);
	return (ft_singleton()->ret);
}
