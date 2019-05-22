/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_handle_expansions.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/15 18:33:53 by tde-jong       #+#    #+#                */
/*   Updated: 2019/05/20 14:27:13 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	env_str_len(char *env_str)
{
	size_t i;

	i = 0;
	while (env_str[i] != '\0' && !ft_isspace(env_str[i]) && env_str[i] != '$' &&
			env_str[i] != '/')
		i++;
	return (i);
}

static char		*handle_tilde(char *str)
{
	t_env	*item;
	char	*newstr;

	item = env_get_by_key("HOME");
	if (item == NULL)
		return (NULL);
	newstr = ft_strnew(ft_strlen(str + 1) + ft_strlen(item->entry + 5));
	if (newstr == NULL)
		return (NULL);
	ft_strcpy(newstr, item->entry + 5);
	ft_strcat(newstr, str + 1);
	return (newstr);
}

static char		*handle_dollarsign(char *str, size_t i)
{
	t_env	*item;
	char	*newstr;

	item = env_get_by_nkey(str + i + 1, env_str_len(str + i + 1));
	if (item == NULL)
		str[i] = '\0';
	else
	{
		newstr = ft_strnew((i - 1) +
			ft_strlen(item->entry + env_str_len(str + i + 1) + 1) +
			ft_strlen(str + ft_max(i, 0) + env_str_len(str + i + 1) + 1));
		if (newstr == NULL)
			return (NULL);
		ft_memcpy(newstr, str, ft_max(i, 0));
		ft_strcat(newstr, item->entry + env_str_len(str + i + 1) + 1);
		ft_strcat(newstr, str + ft_max(i, 0) + env_str_len(str + i + 1) + 1);
		return (newstr);
	}
	return (NULL);
}

static char		*expand(char *str)
{
	size_t	i;

	if (str[0] == '~' && (str[1] == '/' || str[1] == '\0'))
		return (handle_tilde(str));
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$')
			return (handle_dollarsign(str, i));
		i++;
	}
	return (NULL);
}

char			**parser_handle_expansions(char **cmd)
{
	char	*temp;
	size_t	i;

	i = 0;
	while (cmd[i] != NULL)
	{
		temp = expand(cmd[i]);
		if (temp != NULL)
		{
			if (temp != cmd[i])
				i--;
			free(cmd[i + 1]);
			cmd[i + 1] = temp;
		}
		i++;
	}
	return (cmd);
}
