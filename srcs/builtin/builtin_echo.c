/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_echo.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/01 14:18:01 by tde-jong       #+#    #+#                */
/*   Updated: 2019/05/22 12:57:54 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_echo(char **cmd, char *status)
{
	bool	n;
	size_t	i;

	i = 1;
	if (cmd[1] != NULL && ft_strequ(cmd[1], "-n"))
	{
		n = false;
		i++;
	}
	else
		n = true;
	while (cmd[i] != NULL)
	{
		ft_putstr(cmd[i]);
		if (cmd[i + 1] != NULL && cmd[i + 1][0] != '\0')
			ft_putchar(' ');
		i++;
	}
	if (n == true)
		ft_putchar('\n');
	*status = 0;
}
