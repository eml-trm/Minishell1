/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 16:24:14 by etermeau          #+#    #+#             */
/*   Updated: 2014/11/16 19:20:35 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*str;

	if ((str = (void *)malloc(size * sizeof(str))))
		ft_bzero(str, size);
	else
		return (NULL);
	return (str);
}
