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

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> //open
#include "ft_sh1.h"

void	ft_exec_fork(t_env *env, char *line)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		ft_command(env, line);
	else
		wait(NULL);
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
	while (42)
	{
		ft_print_magenta("# shell #> ");
		get_next_line(0, &line);
		ft_lexer(line);
		// ft_exec_fork(tmp, line);
	}
}

int			main(int ac, char **av, char **envp)
{
	if (ac == 1)
		ft_sh(av, envp);
	// ft_putnbr(ft_singleton()->ret);
	return (ft_singleton()->ret);
}
