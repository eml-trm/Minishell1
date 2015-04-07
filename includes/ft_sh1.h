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
	t_lex			*lst;
	int				ret;
	char			*pwd;
	struct s_glob	*next;
}					t_glob;

/* erreur */
int					ft_access(char *path);
void				code_erreur(int code, char *str);

/* recup infos */
int					ft_strplen(char **str);
void				ft_print_tab(char **tab);
void				ft_new_env(char *name, char *info, int i);
char				*ft_getcwd(void);
char				*ft_getenv(char *name);

/* parser */
char				*recup_dir(t_lex *lst);
void				ft_find_arg(t_lex *list);
int					ft_find_command(t_lex *elem, t_env *env);
void				ft_parser(t_lex **list, char *line);

/* lexer */
t_lex				*ft_new_lex(char *word);
void				ft_add_lex(t_lex **list, char *word);
void				ft_lexer(char *line);

/* print */
void				ft_print_tab(char **tab);
void				ft_print_lex(t_lex *lex);
void				ft_print_env(t_env *env);

/* list */
t_glob				*ft_singleton(void);
void				ft_add_elem(t_env **list, char *name);
t_env				*ft_new_elem(char *elem);
void				ft_list(t_env **list, t_env *new, t_env *tmp);

/* init */
int					verif_path(t_lex *lst, t_env *env);
char				**init_tab(t_env *list);

/* commandes*/
int					ft_exit(char **str);
void				ft_unsetenv(char **str);
void				add_env(t_env **temp, char *name, char *data);
void				ft_setenv(char **str);
void				exec_env(char **str, int *i, int isnew_env, char **env);
char				**build_env(t_env *env);
char				**new_env(char **str);
int					is_exec(char **newenv, char *str);
int					search_cmd(char **str);
void				ft_env(char **str);
void				ft_cd(char **cmd);
void				ft_exec_fork(t_lex *list, char **tab, char *line, int cmd);
void				ft_exec_cmd(t_lex *list, char **tab, char *line, int cmd);

#endif
