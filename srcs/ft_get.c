/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 14:42:41 by etermeau          #+#    #+#             */
/*   Updated: 2015/03/04 14:42:45 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> // getcwd
#include "ft_sh1.h"

char		*ft_getenv(char *name)
{
	t_env	*temp;

	temp = ft_singleton()->env;
	while (temp)
	{
		if (ft_strcmp(name, temp->name) == 0)
			return (temp->data);
		temp = temp->next;
	}
	return (NULL);
}

char		*ft_getcwd(void)
{
	char	*path;
	int		i;

	i = 1;
	while (42)
	{
		path = NULL;
		if (!(path = (char *)ft_memalloc(i * sizeof(path))))
			return (NULL);
		if (getcwd(path, i))
			return (path);
		if (path)
			free(path);
		i += 1;
		if (i > 255)
			return (NULL);
	}
}
