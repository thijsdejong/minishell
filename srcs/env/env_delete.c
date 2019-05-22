/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env_delete.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/09 15:07:04 by tde-jong       #+#    #+#                */
/*   Updated: 2019/05/10 09:32:12 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_delete(t_env *env)
{
	t_env *cur;
	t_env *prev;

	cur = g_env;
	while (cur != NULL && cur != env)
	{
		prev = cur;
		cur = cur->next;
	}
	if (cur == NULL)
		return ;
	if (cur == g_env)
		g_env = cur->next;
	else
		prev->next = cur->next;
	free(cur->entry);
	free(cur);
}
