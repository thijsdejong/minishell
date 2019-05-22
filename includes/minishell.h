/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 14:39:44 by tde-jong       #+#    #+#                */
/*   Updated: 2019/05/20 15:39:47 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define SHELLPREFIX	"$"
# define SHELLNAME		"minishell"

# define FUNCT_SUCCESS	1
# define FUNCT_FAILURE	0
# define EXIT_INVALID	2

# include <stdbool.h>
# include <dirent.h>
# include <limits.h>
# include "libft.h"

/*
**-----------------------------environment--------------------------------------
*/

typedef struct	s_env
{
	char			*entry;
	struct s_env	*next;
}				t_env;

t_env			*g_env;

/*
**--------------------------------builtin---------------------------------------
*/

int				builtin(char **cmd, char *status);
void			builtin_echo(char **cmd, char *status);
void			builtin_cd(char **cmd, char *status);
void			builtin_setenv(char **cmd, char *status);
void			builtin_unsetenv(char **cmd, char *status);
void			builtin_env(char **cmd, char *status);
void			builtin_exit(char **cmd, char *status);

/*
**----------------------------------env-----------------------------------------
*/

t_env			*env_add_key_value(char *key, char *value);
void			env_delete(t_env *env);
bool			env_duplicate(char **envp);
t_env			*env_get_by_key(char *key);
t_env			*env_get_by_nkey(char *key, size_t n);
char			*env_join_key_value(char *key, char *c, char *value);
bool			env_set_key_value(char *key, char *value);
char			**env_to_array(void);

/*
**---------------------------------shell----------------------------------------
*/

void			shell_display_prompt(void);
void			shell_run(void);

/*
**---------------------------------parser---------------------------------------
*/

char			**parser_handle_expansions(char **cmd);
char			**parser_split_input(char *input);
char			**parser(char *input);

/*
**-------------------------------evaluator--------------------------------------
*/

int				evaluator(char **cmd, char *status);

/*
**-------------------------------external--------------------------------------
*/

int				external(char **cmd, char *status);

#endif
