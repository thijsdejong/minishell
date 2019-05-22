/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_cd.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/01 14:25:51 by tde-jong       #+#    #+#                */
/*   Updated: 2019/05/20 15:35:04 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*real_path(char *location)
{
	char *path;
	char *temp;
	char buff[PATH_MAX];

	if (location != NULL)
	{
		if (location[0] == '/')
			return (location);
		else
		{
			getcwd(buff, PATH_MAX);
			temp = ft_strjoin(buff, "/");
			path = ft_strjoin(temp, location);
			free(temp);
			return (path);
		}
	}
	return (NULL);
}

static bool	change_dir(char *path)
{
	char	buff[PATH_MAX];
	t_env	*item;

	getcwd(buff, PATH_MAX);
	if (chdir(path) == EXIT_SUCCESS)
	{
		item = env_get_by_key("PWD");
		if (item == NULL)
			env_add_key_value("PWD", buff);
		getcwd(buff, PATH_MAX);
		env_set_key_value("OLDPWD", env_get_by_key("PWD")->entry + 4);
		env_set_key_value("PWD", buff);
		return (true);
	}
	ft_printf("cd: Error changing directory\n");
	return (false);
}

static void	change_dir_by_key(char *key)
{
	t_env	*item;

	item = env_get_by_key(key);
	if (item != NULL)
		change_dir(item->entry + (ft_strlen(key) + 1));
}

void		builtin_cd(char **cmd, char *status)
{
	char	*temp;

	*status = 0;
	if (cmd[1] != NULL && cmd[2] != NULL)
	{
		*status = 2;
		ft_printf("cd: Too many arguments\n");
	}
	else if (cmd[1] != NULL)
	{
		if (ft_strequ(cmd[1], "-"))
			change_dir_by_key("OLDPWD");
		else
		{
			temp = real_path(cmd[1]);
			(temp != NULL) ? change_dir(cmd[1]) : 0;
			if (temp != cmd[1])
				free(temp);
		}
	}
	else if (cmd[1] == NULL)
		change_dir_by_key("HOME");
}
