/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_env.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/01 14:25:46 by tde-jong       #+#    #+#                */
/*   Updated: 2019/05/20 15:39:40 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_env(char **cmd, char *status)
{
	t_env *item;

	*status = 0;
	(void)cmd;
	item = g_env;
	while (item != NULL)
	{
		ft_printf("%s\n", item->entry);
		item = item->next;
	}
}
