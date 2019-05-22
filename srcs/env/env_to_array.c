/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env_to_array.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/08 14:02:44 by tde-jong       #+#    #+#                */
/*   Updated: 2019/05/10 09:05:21 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	get_size(t_env *item)
{
	size_t size;

	size = 0;
	while (item != NULL)
	{
		size++;
		item = item->next;
	}
	return (size);
}

static char		**fill_array(t_env *item)
{
	size_t	i;
	size_t	size;
	char	**env;

	size = get_size(item);
	if (size == 0)
		return (NULL);
	env = (char**)ft_memalloc(sizeof(char*) * (size + 1));
	if (env == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		env[i] = item->entry;
		i++;
		item = item->next;
	}
	return (env);
}

char			**env_to_array(void)
{
	t_env	*item;
	char	**env;

	item = g_env;
	env = fill_array(item);
	return (env);
}
