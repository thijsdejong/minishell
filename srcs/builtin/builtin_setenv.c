/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_setenv.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/01 14:25:40 by tde-jong       #+#    #+#                */
/*   Updated: 2019/05/20 15:40:12 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_setenv(char **cmd, char *status)
{
	*status = 0;
	if (cmd[1] != NULL && cmd[2] != NULL && cmd[3] != NULL)
	{
		*status = 2;
		ft_printf("setenv: Too many arguments\n");
	}
	else if (cmd[1] != NULL)
		env_set_key_value(cmd[1], cmd[2]);
	else
		builtin_env(cmd, status);
}
