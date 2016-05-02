/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 13:36:36 by etermeau          #+#    #+#             */
/*   Updated: 2015/03/13 13:42:11 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_count_word(char *line)
{
	int		i;
	int		word;

	i = 0;
	word = 0;
	while (line[i])
	{
		while (line[i] && (line[i] == ' ' || line[i] == '\t'))
			i++;
		if (line[i])
			word++;
		while (line[i] && (line[i] != ' ' && line[i] != '\t'))
			i++;
	}
	return (word);
}
