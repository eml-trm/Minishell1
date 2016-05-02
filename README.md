# Minishell1
#### Realisation of a shell

Program a mini UNIX command shell .
This interpreter should display a prompt and can execute simple command lines.
The following builtins are implemented: ls, cd, setenv, unsetenv, env, exit.
My reference shell is the zsh shell.


## Summary
 1. [Makefile](#makefile)
 2. [Usage](#usage)
 3. [Example](#exemple)

## <a name="makefile">Makefile</a>

| Commande       	|  Actions 	|
|----------------	|----------	|
| `make`      	  | Compile all .c and create an executable "ft_minishell1"  	|
| `make clean`    | Delete all .o.  	|
| `make flcean`  	| Delete all .o and executable 'ft_minishell1'.  	|
| `make re` 	 	| Execute fclean and make.  	|

## <a name="usage">Usage</a>

./ft_minishell1

## <a name="exemple">Example</a>

```c
# shell #> ls
Makefile	ft_minishell1	libft
auteur		includes	srcs

# shell #> cd srcs

# shell #> ls
ft_access_cd.c		ft_fork.c		ft_parser.c
ft_builtin_cd.c		ft_get.c		ft_print.c
ft_builtin_env.c	ft_init_tab.c		ft_setenv.c
ft_builtin_exit.c	ft_lexer.c		ft_singleton.c
ft_check_access.c	ft_lexer_list.c		main.c
ft_command.c		ft_list.c
ft_erreur.c		ft_new_env.c
```

```c
# shell #> env
SSH_AUTH_SOCK=/private/tmp/com.apple.launchd.eoKyt5NtiL/Listeners
Apple_PubSub_Socket_Render=/private/tmp/com.apple.launchd.tmGwcYFxJe/Render
COLORFGBG=7;0
ITERM_PROFILE=Default
XPC_FLAGS=0x0
PWD=/nfs/2014/e/etermeau/42/sh1
SHELL=/bin/zsh
SECURITYSESSIONID=186a9
LC_CTYPE=UTF-8
TERM_PROGRAM=iTerm.app
PATH=/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/bin:/usr/local/munki
COMMAND_MODE=unix2003
TERM=xterm-256color
HOME=/nfs/2014/e/etermeau
TMPDIR=/var/folders/zz/zyxvpxvq6csfxvn_n00012zw0008qz/T/
USER=etermeau
XPC_SERVICE_NAME=0
LOGNAME=etermeau
ITERM_SESSION_ID=w0t0p1
__CF_USER_TEXT_ENCODING=0x22FF:0x0:0x1
SHLVL=1
OLDPWD=/nfs/2014/e/etermeau/42
ZSH=/nfs/2014/e/etermeau/.oh-my-zsh
PAGER=less
LESS=-R
LSCOLORS=Gxfxcxdxbxegedabagacad
_=/nfs/2014/e/etermeau/42/sh1/./ft_minishell1

# shell #> setenv new data

# shell #> env
[...]
LESS=-R
LSCOLORS=Gxfxcxdxbxegedabagacad
_=/nfs/2014/e/etermeau/42/sh1/./ft_minishell1
new=data
```

```c
# shell #> unsetenv new

# shell #> env
[...]
ZSH=/nfs/2014/e/etermeau/.oh-my-zsh
PAGER=less
LESS=-R
LSCOLORS=Gxfxcxdxbxegedabagacad
_=/nfs/2014/e/etermeau/42/sh1/./ft_minishell1

```
