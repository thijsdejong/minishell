/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env_set_key_value.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/10 11:14:55 by tde-jong       #+#    #+#                */
/*   Updated: 2019/05/10 19:13:15 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	env_set_key_value(char *key, char *value)
{
	t_env *item;

	item = env_get_by_key(key);
	if (item == NULL)
	{
		if (env_add_key_value(key, value) == false)
			return (false);
	}
	else
	{
		free(item->entry);
		item->entry = env_join_key_value(key, "=", value);
		if (item->entry == NULL)
			return (false);
	}
	return (true);
}
