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

typedef struct		s_lex
{
	char			*word;
	struct s_lex	*next;
}					t_lex;

typedef struct		s_env
{
	char			*name;
	char			*data;
	struct s_env	*next;
}					t_env;

typedef struct		s_glob
{
	t_env			*env;
	int				ret;
	struct s_glob	*next;
}					t_glob;

/* parser */
char				**ft_find_arg(t_lex *list);
int					ft_find_command(t_lex *elem);
void				ft_parser(t_lex **list, char *line);

/* lexer */
t_lex				*ft_new_lex(char *word);
void				ft_add_lex(t_lex **list, char *word);
void				ft_lexer(char *line);

/* print */
void				ft_print_env(t_env *env);

/* list */
t_glob				*ft_singleton(void);
void				ft_add_elem(t_env **list, char *name);
t_env				*ft_new_elem(char *elem);
void				ft_list(t_env **list, t_env *new, t_env *tmp);

/* init */
char				**init_tab(t_env *list);

/* commandes*/
// void				ft_exit(int status);
void				ft_exec_fork(t_lex *list, char **tab);
void				ft_command(t_lex *list, char **tab);

#endif
