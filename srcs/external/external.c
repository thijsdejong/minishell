/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   external.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/07 16:21:20 by tde-jong       #+#    #+#                */
/*   Updated: 2019/05/20 14:28:12 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		**get_paths(void)
{
	t_env *env;

	env = env_get_by_key("PATH");
	if (env == NULL)
		return (NULL);
	return (ft_strsplit(env->entry + 5, ':'));
}

static char		*check_dir(DIR *d, char *filename, char *path)
{
	struct dirent	*dir;

	dir = readdir(d);
	while (dir != NULL)
	{
		if (ft_strequ(filename, dir->d_name))
		{
			return (env_join_key_value(path, "/", filename));
		}
		dir = readdir(d);
	}
	return (NULL);
}

static char		*search(char *filename)
{
	DIR				*d;
	char			**paths;
	char			*ret;
	char			**tofree;

	ret = NULL;
	paths = get_paths();
	tofree = paths;
	while (paths != NULL && *paths != NULL)
	{
		d = opendir(*paths);
		if (d == NULL)
			break ;
		ret = check_dir(d, filename, *paths);
		closedir(d);
		if (ret != NULL)
			break ;
		paths++;
	}
	ft_freearray(tofree);
	return (ret);
}

static int		exectute(char **cmd, char *status)
{
	char	**env;
	pid_t	pid;
	bool	error;

	error = false;
	pid = 0;
	env = env_to_array();
	if (env == NULL)
		return (FUNCT_FAILURE);
	pid = fork();
	if (pid == -1)
		return (FUNCT_FAILURE);
	if (pid == 0)
		if (execve(cmd[0], cmd, env) == -1)
			error = true;
	wait(&pid);
	if (WIFEXITED(pid))
		*status = (char)WEXITSTATUS(pid);
	free(env);
	return ((error) ? FUNCT_FAILURE : FUNCT_SUCCESS);
}

int				external(char **cmd, char *status)
{
	char *filename;

	if (cmd[0][0] != '/' && !ft_strnequ(cmd[0], "./", 2))
	{
		filename = search(cmd[0]);
		if (filename == NULL)
			return (FUNCT_FAILURE);
		free(cmd[0]);
		cmd[0] = filename;
	}
	if (exectute(cmd, status) == FUNCT_FAILURE)
		return (FUNCT_FAILURE);
	return (FUNCT_SUCCESS);
}
