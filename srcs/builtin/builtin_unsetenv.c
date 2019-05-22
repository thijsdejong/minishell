/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_unsetenv.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/01 14:25:37 by tde-jong       #+#    #+#                */
/*   Updated: 2019/05/20 15:39:33 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_unsetenv(char **cmd, char *status)
{
	t_env	*env;
	size_t	i;

	*status = 0;
	i = 1;
	while (cmd[i] != NULL)
	{
		env = env_get_by_key(cmd[i]);
		if (env != NULL)
			env_delete(env);
		i++;
	}
}
