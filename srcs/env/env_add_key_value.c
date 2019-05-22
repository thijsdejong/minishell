/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env_add_key_value.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/08 15:36:39 by tde-jong       #+#    #+#                */
/*   Updated: 2019/05/10 19:13:04 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*env_add_key_value(char *key, char *value)
{
	t_env *item;
	t_env *env;

	env = g_env;
	item = (t_env*)ft_memalloc(sizeof(t_env));
	if (item == NULL || key == NULL)
		return (NULL);
	item->entry = env_join_key_value(key, "=", value);
	if (item->entry == NULL)
		return (NULL);
	while (env != NULL && env->next != NULL)
		env = env->next;
	if (env == NULL)
		g_env = item;
	else
		env->next = item;
	return (env);
}
