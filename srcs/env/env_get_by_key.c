/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env_get_by_key.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/09 15:13:07 by tde-jong       #+#    #+#                */
/*   Updated: 2019/05/20 10:47:03 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*env_get_by_nkey(char *key, size_t n)
{
	t_env	*item;

	if (key != NULL)
	{
		item = g_env;
		while (item != NULL)
		{
			if (ft_strnequ(key, item->entry, n) && item->entry[n] == '=')
				return (item);
			item = item->next;
		}
	}
	return (NULL);
}

t_env	*env_get_by_key(char *key)
{
	return (env_get_by_nkey(key, ft_strlen(key)));
}
