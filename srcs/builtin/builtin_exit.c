/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_exit.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/01 14:25:33 by tde-jong       #+#    #+#                */
/*   Updated: 2019/05/13 11:39:37 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_exit(char **cmd, char *status)
{
	size_t i;

	ft_putendl("exit");
	if (cmd[1] == NULL)
		exit(*status);
	else
	{
		i = 0;
		while (cmd[1][i] != '\0')
		{
			if (!ft_isdigit(cmd[1][i]))
			{
				ft_printf("exit: %s: numeric argument required\n",
							SHELLNAME, cmd[1]);
				exit(EXIT_INVALID);
			}
			i++;
		}
		exit(ft_atoi(cmd[1]));
	}
}
