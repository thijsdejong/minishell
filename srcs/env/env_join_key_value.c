/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env_join_key_value.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/10 10:56:17 by tde-jong       #+#    #+#                */
/*   Updated: 2019/05/10 19:12:25 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*env_join_key_value(char *key, char *c, char *value)
{
	char	*entry;
	size_t	len;

	len = ft_strlen(key) + 1;
	if (value != NULL)
		len += ft_strlen(value);
	entry = ft_strnew(len);
	if (entry == NULL)
		return (NULL);
	ft_strcpy(entry, key);
	ft_strcat(entry, c);
	if (value != NULL)
		ft_strcat(entry, value);
	return (entry);
}
