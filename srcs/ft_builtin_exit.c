/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/07 13:28:03 by etermeau          #+#    #+#             */
/*   Updated: 2015/04/07 13:28:04 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "ft_sh1.h"

// static int  is_num(char *str)
// {
// 	int		i;
// 	int		len;

// 	i = 0;
// 	len = ft_strlen(str);
// 	while (str[i] == ' ' || str[i] == '\t')
// 		i++;
// 	while (str[i])
// 	{
// 		if (ft_isdigit(str[i]) == 0)
// 			return (1);
// 		i++;
// 	}
// 	if (len > 10)
// 		return (1);
// 	else if (len == 10)
// 	{
// 		if (ft_strcmp(str, "2147483647") > 0)
// 			return (1);
// 	}
// 	return (0);
// }

// static int	ft_nbline(char **str)
// {
// 	int		i;

// 	i = 0;
// 	if (str)
// 	{
// 		while (*(str++))
// 			i++;
// 	}
// 	return (i);
// }

int		ft_exit(char **str)
{
	exit(0);
	(void)str;
	// int		i;
	// int		num;
	// num = 0;
	// i = ft_nbline(str);
	// if (i > 2)
	// {
	// 	code_erreur(9, NULL);
	// 	return (0);
	// }
	// else if (i == 2)
	// {
	// 	if (is_num(str[1]) == 0)
	// 		num = ft_atoi(str[1]);
	// }
	// else
	// 	num = 0;
	// ft_singleton()->ret = num;
	// return (ft_singleton()->ret);
}
