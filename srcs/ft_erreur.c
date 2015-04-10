/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erreur.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 17:13:37 by etermeau          #+#    #+#             */
/*   Updated: 2015/03/30 17:14:49 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "ft_sh1.h"

static void	erreur_env(int code, char *str)
{
	if (code == 7)
	{
		ft_print_color(RED, "Usage: ", 2);
		ft_print_color(RED, str, 2);
		ft_print_color(RED, " [name] [data]\n", 2);
	}
	if (code == 8)
	{
		ft_print_color(RED, "Usage: ", 2);
		ft_print_color(RED, str, 2);
		ft_print_color(RED, " [name] \n", 2);
	}
}

static void	erreur_cd(int code, char *str)
{
	if (code == 3)
	{
		ft_print_color(RED, "cd: ", 2);
		ft_print_color(RED, str, 2);
		ft_print_color(RED, ": No such file or directory\n", 2);
	}
	if (code == 4)
	{
		ft_print_color(RED, "cd: ", 2);
		ft_print_color(RED, ": Permission denied\n", 2);
		ft_print_color(RED, str, 2);
	}
	if (code == 5)
	{
		ft_print_color(RED, "cd: ", 2);
		ft_print_color(RED, ": Not a directory\n", 2);
		ft_print_color(RED, str, 2);
	}
	if (code == 6)
	{
		ft_print_color(RED, "cd: ", 2);
		ft_print_color(RED, "Too many arguments\n", 2);
	}
}

void	code_erreur(int code, char *str)
{
	if (code == 0)
		ft_print_color(RED, "Malloc error\n", 2);
	if (code == 1)
		ft_print_color(RED, "Permission denied\n", 2);
	if (code == 2)
	{
		ft_print_color(RED, "sh: ", 2);
		ft_print_color(RED, str, 2);
		ft_print_color(RED, ": command not found\n", 2);
	}
	if (code == 9)
	{
		ft_print_color(RED, "exit: ", 2);
		ft_print_color(RED, " Too many arguments\n", 2);
	}
	if (code == 10)
		ft_print_color(RED, "Error: execve\n", 2);
	if (code >= 3 || code <= 6)
		erreur_cd(code, str);
	if (code >= 7)
		erreur_env(code, str);
}
