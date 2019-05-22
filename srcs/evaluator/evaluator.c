/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   evaluator.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/07 14:29:38 by tde-jong       #+#    #+#                */
/*   Updated: 2019/05/16 10:17:26 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	evaluator(char **cmd, char *status)
{
	if (cmd == NULL || cmd[0] == NULL)
	{
		ft_freearray(cmd);
		return (0);
	}
	if (!(builtin(cmd, status) == FUNCT_SUCCESS ||
			external(cmd, status) == FUNCT_SUCCESS))
		ft_printf("%s: Command not found.\n", cmd[0]);
	ft_freearray(cmd);
	return (EXIT_SUCCESS);
}
