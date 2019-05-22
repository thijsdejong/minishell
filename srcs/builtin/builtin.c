/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/01 14:17:50 by tde-jong       #+#    #+#                */
/*   Updated: 2019/05/20 15:40:03 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin(char **cmd, char *status)
{
	if (ft_strequ(cmd[0], "echo"))
		builtin_echo(cmd, status);
	else if (ft_strequ(cmd[0], "cd"))
		builtin_cd(cmd, status);
	else if (ft_strequ(cmd[0], "setenv"))
		builtin_setenv(cmd, status);
	else if (ft_strequ(cmd[0], "unsetenv"))
		builtin_unsetenv(cmd, status);
	else if (ft_strequ(cmd[0], "env"))
		builtin_env(cmd, status);
	else if (ft_strequ(cmd[0], "exit"))
		builtin_exit(cmd, status);
	else
		return (FUNCT_FAILURE);
	return (FUNCT_SUCCESS);
}
