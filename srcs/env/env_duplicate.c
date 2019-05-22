/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env_duplicate.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/01 15:08:25 by tde-jong       #+#    #+#                */
/*   Updated: 2019/05/10 12:13:47 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	add(char *entry)
{
	t_env *item;
	t_env *env;

	env = g_env;
	item = (t_env*)ft_memalloc(sizeof(t_env));
	if (item == NULL || entry == NULL)
		return (false);
	if (g_env == NULL)
		g_env = item;
	item->entry = ft_strdup(entry);
	if (item->entry == NULL)
		return (false);
	while (env != NULL && env->next != NULL)
		env = env->next;
	if (env == NULL)
		env = item;
	else
		env->next = item;
	return (true);
}

bool		env_duplicate(char **envp)
{
	size_t	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (add(envp[i]) == false)
			return (false);
		i++;
	}
	return (true);
}
