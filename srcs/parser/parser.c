/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 16:14:38 by tde-jong       #+#    #+#                */
/*   Updated: 2019/05/16 10:14:25 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**parser(char *input)
{
	char **cmd;
	char **cmd_split;

	cmd_split = parser_split_input(input);
	if (cmd_split == NULL)
	{
		ft_freearray(cmd_split);
		return (NULL);
	}
	cmd = parser_handle_expansions(cmd_split);
	return (cmd);
}
