/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 21:49:53 by etermeau          #+#    #+#             */
/*   Updated: 2015/02/26 21:49:57 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH1
# define FT_SH1

# include "libft.h"


typedef struct		s_env
{
	char			*name;
	char			*data;
	int				*ret;
	struct s_env	*next;
}					t_env;

typedef struct		s_glob
{
	t_env			*env;
	int				ret;
	struct s_glob	*next;
}					t_glob;

/* lexer */
void				ft_lexer(char *line);

/* print */
void				ft_print_list(t_env *env);

/* list */
t_glob				*ft_singleton(void);
void				ft_add_elem(t_env **list, char *name);
t_env				*ft_new_elem(char *elem);
void				ft_list(t_env **list, t_env *new, t_env *tmp);

/* commandes*/
void				ft_exit(int status);
void				ft_command(t_env *env, char * line);

#endif
