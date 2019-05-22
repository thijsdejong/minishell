/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 14:39:02 by tde-jong       #+#    #+#                */
/*   Updated: 2019/05/21 10:24:36 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	g_env = NULL;
	if (env_duplicate(envp) == false)
		return (EXIT_FAILURE);
	shell_run();
	return (EXIT_SUCCESS);
}
