/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_magenta.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 14:30:08 by etermeau          #+#    #+#             */
/*   Updated: 2015/03/01 14:30:43 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_magenta(char *str)
{
	ft_putstr(MAGENTA);
	ft_putstr(str);
	ft_putstr(RESET);
}
